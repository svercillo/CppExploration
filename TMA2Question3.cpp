//: TMA2Question3.cpp

/* 
 Title: TMA2Question3.cpp
 Description: Text Class
 Date: December 11, 2019
 Author: Stefan Vercillo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate proper format for documentation, test plans and comments.
 	Also demonstrate user prompts, keyboard input, simple calculations and output.
    Demonstrate ability to use a class in c++ and initialize an instance of the class 
    to read a file and return the contents of the file.

 Compilation:
 (OPTION 1: Manual)
 Compile: g++ TMA2Question3.cpp -o TMAQuestion3
 Execution: ./TMA2Question1
 
 (OPTION 2: Makefile)
 Comiple: make 
 Execution: make run
 Delete Compiled Object: make clean


 Notes: in Cygwin, main must return type int
 
 Classes: Text

    Constuctors:
        There is a defualt constructor implicitly executed on object instatiation
        setAllDVD is the secondary constructor executed explicity (open and reads file)

    Destructors:
        None   
    
    Memory Notes: 
        A pointer is used to initialize the object and allocate memory.
        This memory is then deleted manually

Variables:
    fileName -  string used to store file name (one line only)
    textFile - file stream that is used and opened using fileName   
    nextLine - string in file is used as temp var to hold the next line of a file
    text - point to an instance of the Text classs
*/

/*
 TEST PLAN
 
 Normal case:
    Please enter the file you'd like to open and read.....
    program3.txt
    This is the file contents of  program3.txt:
    Write a program to manage DVD rental in a video rental store. Create an abstract data type that represents a DVD in this store. Consider all the data and operations that may be necessary for the DVD type to work well within a rental management system. Include a print() member function that displays all the information about the DVD. Test your data type by creating an array of ten DVD instances and filling them using information read from a test input file that you create. Display the DVD information.
    Write a program in which you create a Hen class. Inside this class, nest a Nest class. Inside Nest, place an Egg class. Each class should have a display() member function. For each class, create a constructor and a destructor that prints an appropriate message when it is called. In main(), create an instance of each class using new and call the display() function for each one. After calling display(), free the storage using delete.
    Write a program in which you create a Text class that contains a string object to hold the text of a file. Give it two constructors: a default constructor and a constructor that takes a string argument that is the name of the file to open. When the second constructor is used, open the file and read the contents of the file into the string member object. Add a member function contents() to return the string so that you can display it. In main(), open a file using Text and display the contents.    
            
 Bad Data case 1 (unknown text file or file that is not located in the same directory, or unsupport text file)
    Please enter the file you'd like to open and read.....
    not_a_file.txt
    Unable to open the specified name
 
 Bad Data case 2 (More than one file prvided )
    Please enter the file you'd like to open and read.....
    not_a_file.txt not_a_file2.cpp
    Unable to open the specified name

 Discussion:
    Only a text that is found in the same directory as this program can be used in this program. 
*/

#include <iostream>
#include <string>
#include <fstream>
#include "TMA2Question1.h"
using namespace std;

class Text {
 public:
    string text;

    Text(){}
    bool constructor2 (string fileName){
        string nextLine;
        ifstream textFile (fileName);
        if (textFile.is_open()){
            while (! textFile.eof() ){ 
                getline (textFile,nextLine);
                text += nextLine;
                text += "\n";
            }
            return 1;
        } else {
            cout<< "Unable to open the specified name" << endl;
            return 0;
        }
    }

    string contents(){
        return  text;
    }

};


int main(){
    string fileName;
    Text* text = new Text; 
    
    cout<< "Please enter the file you'd like to open and read....." << endl;

    cin >> fileName;
    if (text->constructor2(fileName)){
        cout << "This is the file contents of  program3.txt:" <<endl; 
        cout << text->contents() << endl;
    }
    delete text;

    return 0;
}

