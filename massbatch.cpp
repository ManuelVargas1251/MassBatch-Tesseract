/*
MassBatch for Tesseract by Manuel Vargas
1/11/17

*/
#include<iostream>
#include<dirent.h>
#include<fstream>

using namespace std;

int main(){
	cout<<"Starting..."<<endl;
	int count=0, num_of_files=0;	//counters
	
	//be able to view current directory
	DIR *dir;
	struct dirent *ent;
	
	//creates output file
	ofstream out("massbatch.bat");
	out<<"@echo off"<<endl;
	
	cout<<"Creating batch file..."<<endl;
	
	if ((dir = opendir ("./")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			//cout<<ent->d_name<<endl;
			if(count>1){	//removes two prior directory names; "." & ".."
			
				//modify string to remove extension
				string file_name = ent->d_name;
				size_t lastindex = file_name.find_last_of(".");	//creates index at delimiter
				
				//only reads file with a "." in the name
				if(lastindex<file_name.length()){
					
					string rawname = file_name.substr(0, lastindex);
					string extension = file_name.substr(lastindex, file_name.length());
					
					//only png/tiff files will be added
					if(extension==".png" || extension==".tiff"){
						cout<<"\t-"<<ent->d_name<<endl;	//print filename
						out<<"tesseract "<<ent->d_name<<" "<<rawname<<endl;	//write to file
						num_of_files++;	//counts how many files are being added
					}
				}
			}
			count++;
		}
		closedir (dir);
	}
	else {
		//couldn't open directory
		cout<<"could not open directory"<<endl;
		return 0;
	}
	
	//Final output
	cout<<"Batch file complete"<<endl;
	cout<<num_of_files<<" files added."<<endl;
	out.close();	//closes stream
}