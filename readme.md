<!-- using shields.io for status buttons -->
![Programming Language](https://img.shields.io/badge/Language-C++-black.svg)
![Status](https://img.shields.io/badge/Status-Passing-green.svg)
![Version](https://img.shields.io/badge/Version-1.2-blue.svg)

#MassBatch for [Tesseract](https://github.com/tesseract-ocr/tesseract)

MassBatch is a console application for Windows that will create a batch file for mass executing [Tesseract](https://github.com/tesseract-ocr/tesseract) conversions; this program will grab all png/tiff/jpg files (by default) in the current directory and create a batch file. This is achieved by scanning all file names in the current directory and adding them each into a formated batch file for execution.

##Running MassBatch
You can download MassBatch [here](https://github.com/ManuelVargas1251/MassBatch-Tesseract/raw/master/Debug/MassBatch.exe). Run the program in the directory where you have your image files. A new batch file called "MassBatch.bat" will be created containing all the tesseract commands for each image conversion for you to run.

Or compile your own by loading the project files into VS. Make sure to add [dirent](https://github.com/tronkko/dirent) to your VS library.

####Command Line Output Example

	Starting...
	Creating batch file
		-doc_53.tiff
		-doc_54.png
		-doc_55.png
	Batch file complete
	3 files added.

####Batch File Output Example

	@echo off
	tesseract doc_53.png doc_53
	tesseract doc_54.png doc_54
	tesseract doc_55.png doc_55

**Note:** By default output from tesseract will be named the same as the input images.
	
##Customizations

###Batch File Name
Rename your output batch file

```
21| ofstream out("massbatch.bat");		//default
21| ofstream out("my_mb.bat");			//custom
21| ofstream out("massbatch.sh");		//bash?
```

###Change Directory
Replace "**./**" with your custom directory

```
26| if ((dir = opendir ("./")) != NULL)	//default
```

###Filetypes
More file extensions can be added depending on your files or if your directory is just images, you can remove this condition.

```
43| if(extension==".png" || extension==".tiff" || extension=".jpg")	//default
43| if(extension==".png" || extension==".tiff" || extension=".jpg" || "extension=".gif")
```	

###Text File Names
Output files will be named the same as the original. For a custom name, replace the "**rawname**" variable below:

```
45| out<<"tesseract \""<<ent->d_name<<"\" \""<<rawname<<"\""<<endl;		//default
45| out<<"tesseract "<<ent->d_name<<" "<<"mytextfile_"<<num_of_files<<endl;		//custom name with incrementation
```

###Other
To add any of tesseract's [options](https://github.com/tesseract-ocr/tesseract/wiki#running-tesseract), add a string after the **rawname** variable.

```
45| out<<"tesseract "<<ent->d_name<<" "<<rawname<<endl;		//default
45| out<<"tesseract "<<ent->d_name<<" "<<rawname<<" -l deu pdf"<<endl;	//german & pdf output
45| out<<"tesseract "<<ent->d_name<<" "<<rawname<<" -l eng hocr"<<endl;	//english & hocr mode
```

##Change Log
1.2.1 - 2/28/17
* Created release executable

1.2 - 2/19/17
* Converted to console application; no longer need to compile, just run the exe

1.1 - 2/14/17
* File names with spaces are now accepted
* File extension 'jpg' is now a default

1.0 - 1/11/17
* Initial release

##References

* [List Directory](http://stackoverflow.com/a/612176)

* [Remove File Extension](http://stackoverflow.com/a/6417880)

* [dirent.h for MSVC](https://github.com/tronkko/dirent)