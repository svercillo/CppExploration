//: TMA1Question1.cpp

/* 
 Title: TMA1Question1.cpp
 Description: Reading lines of a File
 Date: December 11, 2019
 Author: Stefan Vercillo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate proper format for documentation, test plans and comments.
 	Also demonstrate user prompts, keyboard input, simple calculations and output.
    Demostrate understanding of opening files and how to assign the word values from it

 Compile: g++ TMA1Question1.cpp -o TMA1Question1
 Execution: ./TMA1Question1
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Variables:
    fileName -  char array sized for 131 characters - used to store file name (one line only)
    textFile - file stream that is used and opened using fileName   
    count - int used to count the number of words in the text file
*/

/*
 TEST PLAN
 
 Normal case:
    What is the name of the file you'd like to read?  --->     program1.txt
    There is a total number of: 222 word in the selected file
 
 Bad Data case 1 (unknown text file or file that is not located in the same directory)
    What is the name of the file you'd like to read?  --->     asdfasdf
    Error: Unable to open the specified file
 
 Bad Data case 2 (More than one file prvided )
    What is the name of the file you'd like to read?  --->     program1.txt program2.txt
    Error: Unable to open the specified file

 Discussion:
    Only a text that is found in the same directory as this program can be used in this program. The fileName must end in .txt
    for all text files.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// program 1
int main (void) {
    char fileName [132];
    cout << "What is the name of the file you'd like to read?  --->     ";
    cin >> fileName;

    string word;
    ifstream textFile (fileName);
    int count =0;
    if (textFile.is_open()){
        while (textFile >> word){
            count++;
        }
        cout<< "There is a total number of: " << count << " word in the selected file";
        textFile.close();
    } else {
        cout << "Error: Unable to open the specified file"; 
    } 
}