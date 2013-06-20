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
	//go one less up, because you're navigating out of the actual folder the .exe is in for the writing and reading.3
	//implement check for if the file is there. That too.
	bool analyse = false;
	string GA = "<script type=\"text/javascript\">var _gaq = _gaq || [];_gaq.push(['_setAccount', '<%GID%>']);_gaq.push(['_trackPageview']);(function() {var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true; ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);})();</script>";
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
		cout << "\n Error: The \"data\" folder could not be found. Please refer to Section 2.3 of the readme to fix this. \n";
		cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
		cin.get();
		return 0;
	}
	if(ofDirectory::doesDirectoryExist("..//templating",true) == false){
		ofDirectory::createDirectory("..//templating",true);
		cout << "\n Error: The \"templating\" folder could not be found. Please refer to Section 2.4 of the readme to fix this. \n";
		cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
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
		cout << "\n Error: The file \"properties.yml\" is missing. Please refer to Section 2.2 of the Readme to fix this. \n";
        cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
        cin.get();
        
		return 0;
	}
    
	if(ofDirectory::doesDirectoryExist("..//images",true) == true){
        if(ofDirectory::doesDirectoryExist("..//images//16x16",true)==true){
            if(ofDirectory::isDirectoryEmpty("..//images//16x16",true)==true){
                cout << "\n Warning: You have not included a 16x16 image for your application. \n";
                cout << "Should you wish to, once the application has finished running you can add your images into the images/ folders and run the application again. \n";
                
            }
            else{
                ofDirectory sixteen("..//images//16x16");
                sixteen.allowExt("jpeg");
                sixteen.allowExt("jpg");
                sixteen.allowExt("png");
                sixteen.allowExt("gif");
                sixteen.listDir();
                if(sixteen.numFiles() == 0){
                    cout << "\n Error: Your 16x16 image is in an incorrect format. All images should be saved as a '.png', '.jpg', '.jpeg' or '.gif'. Please amend this and run the application again. \n";
                    
                }
                else if(sixteen.numFiles() > 1){
                    cout << "\n Error: There are too many images in the 16x16 folder. Please make sure there is only one. \n";
                    cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
                    cin.get();
                    
                    return 0;
                }
                else{
                    ofFile six = sixteen.getFile(0,ofFile::Reference);
                    string path = sixteen.getPath(0);
                    string name = sixteen.getName(0);
                    ofFile::copyFromTo(ofFilePath::getAbsolutePath(path,true),ofFilePath::getAbsolutePath("..//hangout//16x16."+six.getExtension(),true),false,true);
                    cout << "Your 16x16 image has been added. The image has been renamed \"16x16\". \n";
                }
            }
        }else{
            ofDirectory::createDirectory("..//images//16x16",true);
        }
        
        if(ofDirectory::doesDirectoryExist("..//images//32x32",true)==true){
            if(ofDirectory::isDirectoryEmpty("..//images//32x32",true)==true){
                cout << "\n Warning: You have not included a 32x32 image for your application. \n";
                cout << "Should you wish to, once the application has finished running you can add your images into the images/ folders and run the application again. \n";
                
            }
            else{
                ofDirectory thirtytwo("..//images//32x32");
                thirtytwo.allowExt("jpeg");
                thirtytwo.allowExt("jpg");
                thirtytwo.allowExt("png");
                thirtytwo.allowExt("gif");
                thirtytwo.listDir();
                if(thirtytwo.numFiles() == 0){
                    cout << "\n Error: Your 32x32 image is in an incorrect format. All images should be saved as a '.png', '.jpg', '.jpeg' or '.gif'. Please amend this and run the application again. \n";
                }
                else if(thirtytwo.numFiles() > 1){
                    cout << "\n Error: There are too many images in the 32x32 folder. Please make sure there is only one. \n";
                    cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
                    cin.get();
                    
                    return 0;
                }
                else{
                    ofFile three = thirtytwo.getFile(0,ofFile::Reference);
                    string path = thirtytwo.getPath(0);
                    string name = thirtytwo.getName(0);
                    ofFile::copyFromTo(ofFilePath::getAbsolutePath(path,true),ofFilePath::getAbsolutePath("..//hangout//32x32."+three.getExtension(),true),false,true);
                    cout << "Your 32x32 image has been added. The image has been renamed \"32x32\". \n";
                }
            }
        }else{
            ofDirectory::createDirectory("..//images//32x32",true);
        }
        
        if(ofDirectory::doesDirectoryExist("..//images//240x140",true)==true){
            if(ofDirectory::isDirectoryEmpty("..//images//240x140",true)==true){
                cout << "\n Warning: You have not included a 240x140 image for your application. \n";
                cout << "Should you wish to, once the application has finished running you can add your images into the images/ folders and run the application again. \n";
                
            }
            else{
                ofDirectory twofourty("..//images//240x140");
                twofourty.allowExt("jpeg");
                twofourty.allowExt("jpg");
                twofourty.allowExt("png");
                twofourty.allowExt("gif");
                twofourty.listDir();
                if(twofourty.numFiles() == 0){
                    cout << "\n Error: Your 240x140 image is in an incorrect format. All images should be saved as a '.png', '.jpg', '.jpeg' or '.gif'. Please amend this and run the application again. \n";
                }
                else if(twofourty.numFiles() > 1){
                    cout << "\n Error: There are too many images in the 240x140 folder. Please make sure there is only one. \n";
                    cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
                    cin.get();
                    
                    return 0;
                }
                else{
                    ofFile two = twofourty.getFile(0,ofFile::Reference);
                    string path = twofourty.getPath(0);
                    string name = twofourty.getName(0);
                    ofFile::copyFromTo(ofFilePath::getAbsolutePath(path,true),ofFilePath::getAbsolutePath("..//hangout//240x120."+two.getExtension(),true),false,true);
                    cout << "Your 240x140 image has been added. The image has been renamed \"240x140\". \n";
                }
            }
        }else{
            ofDirectory::createDirectory("..//images//240x140",true);
        }
    }
	else{
		ofDirectory::createDirectory("..//images",true,false);
		cout << "\n Error: The images folder was not found. It has now been created. See the readme section 1.3 for what you can do with images in your application. \n";
		ofDirectory::createDirectory("..//images//16x16",true,false);
		ofDirectory::createDirectory("..//images//32x32",true,false);
		ofDirectory::createDirectory("..//images//240x140",true,false);
	}
    
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
					cout << "\n Error: The iframe_url must begin with \"https://\". If the content is not hosted on a https:// enabled server, the content cannot be displayed. Please refer to Section 2.5 of the readme to fix this. \n";
					//cout << "\n Press Enter to acknowledge. \n";
                    cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
                    cin.get();
                    
					return 0;
				}
			}
			if(value == ""){
				cout << "\n Error: You have not included the "+key+" of your application, please go back to the \"properties.yml\" file and correct this. \n";
				//cout << "\n Press Enter to acknowledge. \n";
                cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
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
        cerr << "\n Error: The template file \"hangout.xml\" is missing. Please refer to Section 2.1 of the Readme to fix this.  \n";
        //cout << "\n Press Enter to acknowledge. \n";
        cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
        cin.get();
        
        return 0;
	}
	try{
        xml.open("hangout.xml", ofFile::ReadWrite,true);
        buff = xml.readToBuffer();
	}
    catch (int n) {
		cout << "\n Error: The hangout file could not be loaded. Please refer to Section 2.6 of the readme to fix this. \n";
		cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
		cin.get();
		return 0;
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
			cout << "The \"hangout\" folder has been created. \n";
		}
		else{
			cout << "\n Error: The hangout folder could not be created. Please refer to Section 2.6 of the readme to fix this. \n";
		}
	}
    
	ofBuffer wbuff;
	wbuff.set(hangout.c_str(), hangout.size());
	if(ofBufferToFile("..//hangout//hangout.xml", wbuff)){
		cout << "The \"hangout.xml\" file has been created in the \"hangout\" folder. This is what needs to be uploaded to your server and linked to in your Google+ App. \n";
	} 
	else{
		cout << "\n Error: The hangout file could not be changed. Please refer to Section 2.6 of the readme to fix this. \n";
	}
	cout << "\n The application has finished! If any errors occured, please fix them by referring to the readme and then run the application again. \n";
	cin.get();
	return 0;
}