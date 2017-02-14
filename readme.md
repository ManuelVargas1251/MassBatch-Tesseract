<!-- using shields.io for status buttons -->
![Programming Language](https://img.shields.io/badge/Language-C++-black.svg)
![Status](https://img.shields.io/badge/Status-Passing-green.svg)
![Version](https://img.shields.io/badge/Version-1.1-blue.svg)

#MassBatch for [Tesseract](https://github.com/tesseract-ocr/tesseract)

MassBatch will create a batch file for mass executing [Tesseract](https://github.com/tesseract-ocr/tesseract) conversions; this program will grab all png/tiff/jpg files in the current directory and create a batch file for you to execute. This is achieved by scanning all file names in the current directory and adding them each into a formated batch file for execution.

##Running MassBatch
Make sure to have Tesseract already [installed](https://github.com/tesseract-ocr/tesseract/wiki#installation) and in your [path](https://www.google.com/search?q=add+directory+to+path+windows).

###Compile
Make sure that you have admin rights when compiling or the batch file will not have the appropriate permissions to run.

	g++ massbatch.cpp -o mb 
	
###Run
Make sure to be in the directory where your files are located.
	
	./mb
	
Now that your batch file has been created, you can run it by double-clicking the file or typing:
	
	./massbatch.bat

If you get a permissions error, type:

	chmod 700 massbatch.bat

and try again.

###Command Line Output

	Starting...
	Creating batch file
		-doc_53.tiff
		-doc_54.png
		-doc_55.png
	Batch file complete
	3 files added.

###Batch File Output 
	@echo off
	tesseract doc_53.png doc_53
	tesseract doc_54.png doc_54
	tesseract doc_55.png doc_55
	
This will make the output text file from Tesseract be named the same as the original image file.
	
##Customizations

###Batch File Name
Rename your output batch file here. You could also change the file extension to work on linux (*.sh)

	20| ofstream out("massbatch.bat");		//default
	20| ofstream out("my_mb.bat");			//custom
	20| ofstream out("massbatch.sh");		//bash

###Change Directory
Replace what's inside the double quotes with your desired location

	25| if ((dir = opendir ("./")) != NULL)	//default

###Filetypes
More file extensions can be added depending on your files or if your entire directory is all just images, you can remove this condition.

	42| if(extension==".png" || extension==".tiff" || extension=".jpg")	//default
	42| if(extension==".png" || extension==".tiff" || extension=".jpg" || "extension=".gif")
	
###Text File Names
Output files will be named the same as the original. If you would like a different name, replace the '**rawname**' variable below:

	44| out<<"tesseract \""<<ent->d_name<<"\" \""<<rawname<<"\""<<endl;	//default
	44| out<<"tesseract "<<ent->d_name<<" "<<"mytextfile_"<<num_of_files<<endl;		//custom name with incrementation

###Other
To add any of tesseract's many [options](https://github.com/tesseract-ocr/tesseract/wiki#running-tesseract), add a string after the '**rawname**' variable.

	44| out<<"tesseract "<<ent->d_name<<" "<<rawname<<endl;		//default
	44| out<<"tesseract "<<ent->d_name<<" "<<rawname<<" -l deu pdf"<<endl;
	44| out<<"tesseract "<<ent->d_name<<" "<<rawname<<" -l eng+deu hocr"<<endl;

##Change Log
###1.1 - 2/14/17
* File names with spaces are now accepted
* File extension 'jpg' is now a default

###1.0 - 1/11/17
* Initial release

##References
* [List Directory](http://stackoverflow.com/a/612176)

* [Remove File Extension](http://stackoverflow.com/a/6417880)