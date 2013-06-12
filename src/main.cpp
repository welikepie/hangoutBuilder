#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "yaml-cpp\yaml.h"

//========================================================================
int main(){
	vector<string> arr;
	vector<string> res;
	int sizeOfStrings = 11;
	string results [11]; //set this to sizeOfStrings.
	string strings [] = {"base_url","app_title","iframe_url","title","icon16x16","icon32x32","icon280x140","ToS","Privacy","Support" ,"app_description"};
	//order of this changes the checks that are happening.
	arr.assign(strings,strings+sizeOfStrings);
	for(int i = 0; i <= sizeOfStrings; i++){
	results[i]="";
	}
	
	for(int i = 0; i < arr.size(); i++) 
	{
		std::cout <<  arr.at(i) + "\n ";
	}

	ofFile file3("properties.yml");
	string propPath = file3.getAbsolutePath();
	
	cout << "\n";
	YAML::Node config = YAML::LoadFile(propPath);
	for(YAML::const_iterator it=config.begin();it != config.end();++it) {
	   std::string key = it->first.as<std::string>();       // <- key
	   std::string value = it->second.as<std::string>(); // <- value
		if(value!=""){
	   cout << key +":"+value+"\n";
		}
		else{
			cout << key +":'' \n";
		}

		if(key.compare(arr.at(0))==0 || key.compare(arr.at(1))==0 || key.compare(arr.at(2))==0 || key.compare(arr.at(3))==0){
			if(key.compare(arr.at(2))==0){
				if(value.find("https://") == std::string::npos){
					cerr << " - Critical Error : URL to display in application needs to be https://. \n";
					system("pause");
					return 0;
				}
			}
			if(value == ""){
				cerr << " - Critical Error : Necessary key '"+key+"' for compilation is missing. \n";
				system("pause");
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
		 system("pause");
	  }	
	cout << "\n";
	string hangout = buff.getText();
	hangout.replace(hangout.find("<%TITLE%>"),9,res.at(1));
	hangout.replace(hangout.find("<%URL%>"),7,res.at(2));
	ofFile test= "";
	string folderPath = test.getAbsolutePath();
	ofFile s = "..//..//hangout";
	if(ofDirectory::createDirectory("..//..//hangout",true,false) == true){
		cout << "Directory 'hangout' created in the path "+s.getAbsolutePath()+" \n";
	}
	else{
		cout << "Directory could not be created. Oh no! \n";
	}
	ofBuffer wbuff;
	wbuff.set(hangout.c_str(), hangout.size());
	if(ofBufferToFile("..//..//hangout//hangout.xml", wbuff)){
		cout << "File hangout.xml created in the hangout directory. \n";
	} 
	else{
		cout << "File could not be written to! Oh no! \n";
	}
	system("pause");
	return 0;
}
