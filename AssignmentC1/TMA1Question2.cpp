//: TMA1Question2.cpp

/* 
 Title: TMA1Question2.cpp
 Description: Reading lines of a File
 Date: December 11, 2019
 Author: Stefan Vercillo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate proper format for documentation, test plans and comments.
 	Also demonstrate user prompts, keyboard input, simple calculations and output.
    Demostrate understanding of opening files and reading lines from it

 Compile: g++ TMA1Question2.cpp -o TMA1Question2
 Execution: ./TMA1Question2
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Variables:
    fileName -  char array sized for 131 characters - used to store file name (one line only)
    textFile - file stream that is used and opened using fileName
    strArray - string array of length 100 strings long
    nextLine - string temporary stores the next line of a file throughout each iteration
    key - string which is the user input in order to see the next line of the given text file
*/

/*
 TEST PLAN
 
 Normal case:
    What is the name of the file you'd like to read?  --->     program2.txt
    Select the 'N' key to see the next line in the file
    n
    Comfort reached gay perhaps chamber his six detract besides add. Moonlight newspaper up he it enjoyment agreeable depending. Timed voice share led his widen noisy young. On weddings believed laughing although material do exercise of. Up attempt offered ye civilly so sitting to. She new course get living within elinor joy. She her rapturous suffering concealed. 
    n

    n 
    Call park out she wife face mean. Invitation excellence imprudence understood it continuing to. Ye show done an into. Fifteen winding related may hearted colonel are way studied. County suffer twenty or marked no moment in he. Meet shew or said like he. Valley silent cannot things so remain oh to elinor. Far merits season better tended any age hunted. 
    n

    n
    Talking chamber as shewing an it minutes. Trees fully of blind do. Exquisite favourite at do extensive listening. Improve up musical welcome he. Gay attended vicinity prepared now diverted. Esteems it ye sending reached as. Longer lively her design settle tastes advice mrs off who. 
    n

    n
    Dependent certainty off discovery him his tolerably offending. Ham for attention remainder sometimes additions recommend fat our. Direction has strangers now believing. Respect enjoyed gay far exposed parlors towards. Enjoyment use tolerably dependent listening men. No peculiar in handsome together unlocked do by. Article concern joy anxious did picture sir her. Although desirous not recurred disposed off shy you numerous securing. 
    -------------    END OF FILE   -------------
 
 Bad Data case 1 (unknown text file or file that is not located in the same directory)
    What is the name of the file you'd like to read?  --->     asdfasdf
    Error: Unable to open the specified file
 
 Bad Data case 2 (More than one file prvided )
    What is the name of the file you'd like to read?  --->     program2.txt program1.txt
    Error: Unable to open the specified file

 Discussion:
    Only a text that is found in the same directory as this program can be used in this program. The fileName must end in .txt
    for all text files.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// program 2
int main (void) {
    char fileName [132];
    cout << "What is the name of the file you'd like to read?  --->     ";
    cin >> fileName;
    cout << "Select the 'N' key to see the next line in the file" << endl;

    string nextLine;
    ifstream textFile (fileName);
    if (textFile.is_open()){
        while (! textFile.eof() ){ 
            string key;
            cin >> key;

            if (key == "n"  || key == "N"){
                getline (textFile,nextLine);
                cout << nextLine << endl;   
            }
        }
        cout <<" -------------    END OF FILE   ------------- ";
        textFile.close();
    } else {
        cout << "Error: Unable to open the specified file"; 
    } 
    return 0;
}
