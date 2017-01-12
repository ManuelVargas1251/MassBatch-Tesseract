<!-- using shields.io for status buttons -->
![Programming Language](https://img.shields.io/badge/Language-C++-black.svg)
![Status](https://img.shields.io/badge/Status-Passing-green.svg)
![Version](https://img.shields.io/badge/Version-1.0-blue.svg)

#MassBatch for [Tesseract](https://github.com/tesseract-ocr/tesseract)

Create a batch file for mass executing tesseract conversions. This program will grab all png/tiff files in the current directory and create the batch file. You still have to execute the file yourself.

This will make the output file name be the same as the original (but will not replace the original because the new file will be a .txt file)

##How
This is achieved by reading all the file names in the current directory and adding them each into a formated file for execution. Make sure to have tesseract already [installed](https://github.com/tesseract-ocr/tesseract/wiki#installation) and in your [path](https://www.google.com/search?q=add+directory+to+path+windows). 

###Compile
Make sure that you have admin rights when compiling or the batch file will not have the appropriate permissions to run.

	g++ massbatch.cpp -o mb 
	
###Run
Make sure to be in the directory where your files are located.
	
	./mb
	
You can double-click the file or run:
	
	./massbatch.bat

If you get '**permission denied**', add:

	chmod 700 massbatch.bat

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
	
##Customizations

###Filetypes
More file extensions can be added depends on your files or if your entire directory is all just images you can remove this condition.

	if(extension==".png" || extension==".tiff")
		
###Batch File Name
Rename your output batch file here. You could also change the file extension to work on linux (*.sh)

	ofstream out("massbatch.bat");
	
###Text File Names
In the code I made it so the file would be named the same as the original. If you would like a different name, replace the '**rawname**' variable below:

	out<<"tesseract "<<ent->d_name<<" "<<<<endl;
	
###Change Directory
Replace what is inside the double quotes with your desired location

	if ((dir = opendir ("./")) != NULL)
	
###Other
To add any of tesseract's many [options](https://github.com/tesseract-ocr/tesseract/wiki#running-tesseract), add a string after the '**rawname**' variable.

	out<<"tesseract "<<ent->d_name<<" "<<rawname<<" -l deu pdf"<<endl;
	
##References
* [List Directory](http://stackoverflow.com/a/612176)

* [Remove File Extension](http://stackoverflow.com/a/6417880)