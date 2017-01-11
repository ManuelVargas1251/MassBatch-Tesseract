<!-- using shields.io for status buttons -->
![Programming Language](https://img.shields.io/badge/Language-C++-black.svg)
![Status](https://img.shields.io/badge/Status-Passing-green.svg)
![Version](https://img.shields.io/badge/Version-v1-blue.svg)

#MassBatch for [Tesseract](https://github.com/tesseract-ocr/tesseract)
by Manuel Vargas

Create a batch file for mass executing tesseract conversions. This program will grab all png/tiff files in the current directory and create the batch file. You still have to execute the file yourself.

This will make the output file name be the same as the original (but will not replace the original because the new file will be a .txt file)

##How
This is achieved by reading all the file names in the current directory and adding them each into a formated file for execution.

###Compile

	g++ massbatch.cpp -o mb
	
###Run
Make sure to be in the directory where your files are located.
	
	./mb
	
##Customizations

###Filetypes
More extensions can be added depends on your files or if your entire directory is all just images you can remove this condition

	if(extension==".png" || extension==".tiff")
		
###Batch File Name

	ofstream out("massbatch.bat");
	
###Text File Names
In the code I made it so the file would be named the same. If you would like a different name, replace the 'rawname' variable below:

	out<<"tesseract "<<ent->d_name<<" "<<rawname<<endl;
	
###Change Directory
Replace what is inside the double quotes with your desired location

	if ((dir = opendir ("./")) != NULL)
			
##References:	
* List directory
http://stackoverflow.com/a/612176/7298219

* Remove File Extension
http://stackoverflow.com/a/6417880/7298219