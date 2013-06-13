#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "yaml-cpp/yaml.h"

//========================================================================
int main(){
	//go one less up, because you're navigating out of the actual folder the .exe is in for the writing and reading.
	//implement check for if the file is there. That too.
    ofFile xmlFile("hangout.xml");
	if(ofFile::doesFileExist(xmlFile.getAbsolutePath(),false) == false){
        cerr << " - Critical Error : XML template file is missing. \n";
        cout << "\n Press Enter to acknowledge. \n";
        cin.get();
        return 0;
	}
    bool analyse = false;
	string GA = "<script type=\"text/javascript\">var _gaq = _gaq || [];_gaq.push(['_setAccount', 'UA-<%GID%>']);_gaq.push(['_trackPageview']);(function() {var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true; ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);})();</script>";
	vector<string> arr;
	vector<string> res;
	int sizeOfStrings = 12;
	string results [12]; //set this to sizeOfStrings.
	string strings [] = {"base_url","app_title","iframe_url","title","icon16x16","icon32x32","icon280x140","ToS","Privacy","Support" ,"app_description","google_analytics_id"};
	//order of this changes the checks that are happening.
	arr.assign(strings,strings+sizeOfStrings);
	for(int i = 0; i < sizeOfStrings; i++){
        results[i]="";
	}
    
	ofFile yaml1("..//templating//properties.yml");
	ofFile yaml2("..//templating//properties.yaml");
    
	string propPath = "";
	if(ofFile::doesFileExist("..//templating//properties.yml",true) == true){
		propPath = yaml1.getAbsolutePath();
        
	}
	else if(ofFile::doesFileExist("..//templating//properties.yaml",true) == true){
		propPath = yaml2.getAbsolutePath();
	}
    
	if(propPath == ""){
		cout << "properties.yml not found in the templating folder. \n";
		cout << "\n Press Enter to acknowledge. \n";
		cin.get();
		return 0;
	}
    
	cout << "\n";
	YAML::Node config = YAML::LoadFile(propPath);
	for(YAML::const_iterator it=config.begin();it != config.end();++it) {
        std::string key = it->first.as<std::string>();       // <- key
        std::string value = it->second.as<std::string>(); // <- value
		if(value!=""){
            //	   cout << key +":"+value+"\n";
		}
		else{
            //		cout << key +":'' \n";
		}
		if(key.compare(arr.at(11))==0 && value != ""){
			analyse = true;
			GA.replace(GA.find("<%GID%>"),7,value);
		}
		if(key.compare(arr.at(0))==0 || key.compare(arr.at(1))==0 || key.compare(arr.at(2))==0 || key.compare(arr.at(3))==0){
			if(key.compare(arr.at(2))==0){
				if(value.find("https://") == std::string::npos){
					cerr << " - Critical Error : URL to display in application needs to be https://. \n";
					cout << "\n Press Enter to acknowledge. \n";
					cin.get();
					return 0;
				}
			}
			if(value == ""){
				cerr << " - Critical Error : Necessary key '"+key+"' for compilation is missing. \n";
				cout << "\n Press Enter to acknowledge. \n";
				cin.get();
				return 0;
			}
		}
		else if(key.compare(arr.at(7))==0 || key.compare(arr.at(8))==0 || key.compare(arr.at(9))==0|| key.compare(arr.at(10))==0){
			if(value == ""){
				cerr << " - Necessary key '"+key+"' for publication is missing. \n";
			}
		}
		for(int i = 0; i < arr.size(); i++)
		{
			if(arr.at(i) == key){
				results[i] = value;
			}
		}
	}
	res.assign(results,results+sizeOfStrings);
	ofFile xml;
	ofBuffer buff;
	
	try{
        xml.open("hangout.xml", ofFile::ReadWrite,true);
        buff = xml.readToBuffer();
	}
    catch (int n) {
        cout << n;
        cout << "\n Press Enter to acknowledge. \n";
		cin.get();
    }
	cout << "\n";
	string hangout = buff.getText();
	//cout << hangout;
	hangout.replace(hangout.find("<%TITLE%>"),9,res.at(1));
	hangout.replace(hangout.find("<%URL%>"),7,res.at(2));
	if(analyse == true){
        hangout.replace(hangout.find("<%GA%>"),6,GA);
	}
	else{
        hangout.replace(hangout.find("<%GA%>"),6," ");
	}
	ofDirectory test("");
	string folderPath = test.getAbsolutePath();
	ofDirectory s("..//hangout");
	if(ofDirectory::createDirectory("..//hangout",true,false) == true){
		cout << "Directory 'hangout' created in the path "+s.getAbsolutePath()+" \n";
	}
	else{
		cout << "Directory could not be created. Oh no! \n";
	}
	ofBuffer wbuff;
	wbuff.set(hangout.c_str(), hangout.size());
	if(ofBufferToFile("..//hangout//hangout.xml", wbuff)){
		cout << "File hangout.xml created in the hangout directory. \n";
	}
	else{
		cout << "File could not be written to! Oh no! \n";
	}
	cout << "\n Press Enter to acknowledge. \n";
	cin.get();
	return 0;
}