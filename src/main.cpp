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
	//go one less up, because you're navigating out of the actual folder the .exe is in for the writing and reading.
	//implement check for if the file is there. That too.
	bool analyse = false;
	string GA = "<script type=\"text/javascript\">var _gaq = _gaq || [];_gaq.push(['_setAccount', 'UA-<%GID%>']);_gaq.push(['_trackPageview']);(function() {var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true; ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);})();</script>";
	vector<string> arr;
	vector<string> res;
	int sizeOfStrings = 3;
	string results [3]; //set this to sizeOfStrings.
	string strings [] = {"app_title","iframe_url","google_analytics_id"};
	//order of this changes the checks that are happening.
	arr.assign(strings,strings+sizeOfStrings);
	for(int i = 0; i < sizeOfStrings; i++){
	results[i]="";
	}
	if(ofDirectory::doesDirectoryExist("..//data",true) == false){
		ofDirectory::createDirectory("..//data",true);
		cout << "The data folder is missing. It has been created. Please find a template XML to insert in to it.";
		cin.get();
		return 0;
	}
	if(ofDirectory::doesDirectoryExist("..//templating",true) == false){
		ofDirectory::createDirectory("..//templating",true);
		cout << "The templating folder is missing. It has been created. Please find a template YML to insert in to it.";
		cin.get();
		return 0;
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

	if(ofDirectory::doesDirectoryExist("..//images",true) == true){
			if(ofDirectory::doesDirectoryExist("..//images//16x16",true)==true){
				if(ofDirectory::isDirectoryEmpty("..//images//16x16",true)==true){
					cout << " - Warning - 16x16 Image folder is empty. \n";
				}
				else{
					ofDirectory sixteen("..//images//16x16");
					sixteen.allowExt("jpeg");
					sixteen.allowExt("jpg");
					sixteen.allowExt("png");
					sixteen.allowExt("gif");
					sixteen.listDir();
					if(sixteen.numFiles() == 0){
						cout << " - Warning - 16x16 Image folder contains no valid types (jpg,png,gif)  \n";
					}
					else if(sixteen.numFiles() > 1){
						cout << " - Warning - 16x16 Image folder contains more than one viable image type. Please select type.  \n";
						cin.get();
						return 0;
					}
					else{
						ofFile six = sixteen.getFile(0,ofFile::Reference);
						string path = sixteen.getPath(0);
						string name = sixteen.getName(0);
						ofFile::copyFromTo(ofFilePath::getAbsolutePath(path,true),ofFilePath::getAbsolutePath("..//hangout//16x16."+six.getExtension(),true),false,true);
						cout << "16 x 16px image copied and renamed into hangouts folder. \n";
					}
				}
			}else{
				ofDirectory::createDirectory("..//images//16x16",true);
			}

			if(ofDirectory::doesDirectoryExist("..//images//32x32",true)==true){
				if(ofDirectory::isDirectoryEmpty("..//images//32x32",true)==true){
					cout << " - Warning - 32x32 Image folder is empty. \n";
				}
				else{
					ofDirectory thirtytwo("..//images//32x32");
					thirtytwo.allowExt("jpeg");
					thirtytwo.allowExt("jpg");
					thirtytwo.allowExt("png");
					thirtytwo.allowExt("gif");
					thirtytwo.listDir();
					if(thirtytwo.numFiles() == 0){
						cout << " - Warning - 32x32 Image folder contains no valid types (jpg,png,gif) \n";
					}
					else if(thirtytwo.numFiles() > 1){
						cout << " - Warning - 32x32 Image folder contains more than one viable image type. Please select type. \n";
						cin.get();
						return 0;
					}
					else{
						ofFile three = thirtytwo.getFile(0,ofFile::Reference);
						string path = thirtytwo.getPath(0);
						string name = thirtytwo.getName(0);
						ofFile::copyFromTo(ofFilePath::getAbsolutePath(path,true),ofFilePath::getAbsolutePath("..//hangout//32x32."+three.getExtension(),true),false,true);
						cout << "32 x 32px image copied and renamed into hangouts folder. \n";
					}
				}
			}else{
				ofDirectory::createDirectory("..//images//32x32",true);
			}
			
			if(ofDirectory::doesDirectoryExist("..//images//240x140",true)==true){
				if(ofDirectory::isDirectoryEmpty("..//images//240x140",true)==true){
					cout << " - Warning - 240x140 Image folder is empty. \n";
				}
				else{
					ofDirectory twofourty("..//images//240x140");
					twofourty.allowExt("jpeg");
					twofourty.allowExt("jpg");
					twofourty.allowExt("png");
					twofourty.allowExt("gif");
					twofourty.listDir();
					if(twofourty.numFiles() == 0){
						cout << " - Warning - 240x140 Image folder contains no valid types (jpg,png,gif) \n";
					}
					else if(twofourty.numFiles() > 1){
						cout << " - Warning - 240x140 Image folder contains more than one viable image type. Please select type. \n";
						cin.get();
						return 0;
					}
					else{
						ofFile two = twofourty.getFile(0,ofFile::Reference);
						string path = twofourty.getPath(0);
						string name = twofourty.getName(0);
						ofFile::copyFromTo(ofFilePath::getAbsolutePath(path,true),ofFilePath::getAbsolutePath("..//hangout//240x120."+two.getExtension(),true),false,true);
						cout << "240 x 140px image copied and renamed into hangouts folder. \n";
					}
				}
			}else{
				ofDirectory::createDirectory("..//images//240x140",true);
			}			
		}
	else{
		ofDirectory::createDirectory("..//images",true,false);
		cout << "images directory not found, has been created.";
		ofDirectory::createDirectory("..//images//16x16",true,false);
		ofDirectory::createDirectory("..//images//32x32",true,false);
		ofDirectory::createDirectory("..//images//240x140",true,false);
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
		if(key.compare(arr.at(2))==0 && value != ""){
			analyse = true;
			GA.replace(GA.find("<%GID%>"),7,value);
		}
		if(key.compare(arr.at(0))==0 || key.compare(arr.at(1))==0){
			if(key.compare(arr.at(1))==0){
				if(value.find("https://") == std::string::npos){
					cerr << " - Critical Error : URL to display in application needs to be https://. \n";
					//cout << "\n Press Enter to acknowledge. \n";
					cin.get();
					return 0;
				}
			}
			if(value == ""){
				cerr << " - Critical Error : Necessary key '"+key+"' for compilation is missing. \n";
				//cout << "\n Press Enter to acknowledge. \n";
				cin.get();
				return 0;
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
	ofFile xmlFile("hangout.xml");
	if(ofFile::doesFileExist(xmlFile.getAbsolutePath(),false) == false){
	cerr << " - Critical Error : XML template file is missing. \n";
				//cout << "\n Press Enter to acknowledge. \n";
				cin.get();
				return 0;
	}
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
	hangout.replace(hangout.find("<%TITLE%>"),9,res.at(0));
	hangout.replace(hangout.find("<%URL%>"),7,res.at(1));
	if(analyse == true){
	hangout.replace(hangout.find("<%GA%>"),6,GA);
	}
	else{
	hangout.replace(hangout.find("<%GA%>"),6," ");
	}
	ofDirectory test("");
	string folderPath = test.getAbsolutePath();
	ofDirectory s("..//hangout");

	if(ofDirectory::doesDirectoryExist("..//hangout",true) == false){
		if(ofDirectory::createDirectory("..//hangout",true,false) == true){
			cout << "Directory 'hangout' created in the path "+s.getAbsolutePath()+" \n";
		}
		else{
			cout << "Directory could not be created. Oh no! \n";
		}
	}
	
	ofBuffer wbuff;
	wbuff.set(hangout.c_str(), hangout.size());
	if(ofBufferToFile("..//hangout//hangout.xml", wbuff)){
		cout << "File hangout.xml created in the hangout directory. \n";
	} 
	else{
		cout << "File could not be written to! Oh no! \n";
	}
	cout << "\n Writing operation finished successfully. \n";
	cin.get();
	return 0;
}
