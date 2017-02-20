// MassBatch.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <dirent.h>	//https://github.com/tronkko/dirent
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "Starting..." << endl;
	int count = 0, num_of_files = 0;	//counters

	//be able to view current directory
	DIR *dir;
	struct dirent *ent;

	//creates output file
	ofstream out("massbatch.bat");
	out << "@echo off" << endl;

	cout << "Creating batch file..." << endl;

	if ((dir = opendir("./")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			//cout<<ent->d_name<<endl;
			if (count>1) {	//removes two prior directory names; "." & ".."

				//modify string to remove extension
				string file_name = ent->d_name;
				size_t lastindex = file_name.find_last_of(".");	//creates index at delimiter

				//only reads file with a "." in the name
				if (lastindex<file_name.length()) {

					string rawname = file_name.substr(0, lastindex);
					string extension = file_name.substr(lastindex, file_name.length());

					//only png/tiff files will be added
					if (extension == ".png" || extension == ".tiff" || extension == ".jpg") {
						cout << "\t-" << ent->d_name << endl;	//print filename to console
						out << "tesseract \"" << ent->d_name << "\" \"" << rawname << "\"" << endl;	//write to file
						num_of_files++;	//counts how many files are being added
					}
				}
			}
			count++;
		}
		closedir(dir);
	}
	else {
		cout << "could not open directory" << endl;
		return 0;
	}
	//insert message into output file to let user know when nothing is added
	if (num_of_files == 0) {
		out << "No files of current type found" << endl;
	}
	//Final output
	cout << num_of_files << " files added." << endl;
	cout << "Batch file complete" << endl;
	out.close();	//closes stream

    return 0;
}

