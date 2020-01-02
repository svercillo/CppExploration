//: TMA2Question1.cpp

/* 
 Title: TMA2Question1.cpp
 Description: DVD Objection for DVD Rental Store 
 Date: December 11, 2019
 Author: Stefan Vercillo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate proper format for documentation, test plans and comments.
 	Also demonstrate user prompts, keyboard input, simple calculations and output.
    Demonstrate ability to use a class in c++ and initialize an instance of the class 
    which is used to imitate the DVD obejct data structre, done by reading a test input 
    file.

 Compile: g++ TMA2Question1.cpp -o TMAQuestion1
 Execution: ./TMA2Question1

 Notes: in Cygwin, main must return type int
 
 Classes: DVD (from TMA2Question1.h header file)

    Constuctors:
        There is a defualt constructor implicitly executed on object instatiation
        setAllDVD is the secondary constructor executed explicity (open and reads file)

    Destructors:
        None   
 
Variables:
    fileName -  string used to store file name (one line only)
    textFile - file stream that is used and opened using fileName   
    nextLine - string in file is used as temp var to hold the next line of a file
    float rating - rating of movie out of 5
    string title -title of movie
    float price - Customer facing price in CAD 
    int ordered - ordered (number of DVDs that were ordered and should be theoretically in the store)
    string releaseDate - year that the DVD was released 
    int rentedOut - number of people that DVD is currenly rented out to
    int totalIter - count total number of lines
    int i - iterator use to count lines in file after instantiation of a new DVD object

*/

/*
 TEST PLAN
 
 Normal case:
    Enter the name of the test inputs....
    testInput.txt
    Ten DVD Test Objects
    { 'id': 1, 'title': Get Out, 'releaseDate':2017, 'price': 14.23, 'rating': 3.2, 'ordered: 12, 'rentedOut': 6, 'remaing DVDs': 6, 'value of remaining': 75.56}           
    { 'id': 2, 'title': Up, 'releaseDate':2016, 'price': 17.24, 'rating': 4.5, 'ordered: 30, 'rentedOut': 27, 'remaing DVDs': 3, 'value of remaining': 45.77}           
    { 'id': 3, 'title': Black Knight , 'releaseDate':2016, 'price': 18.24, 'rating': 5, 'ordered: 50, 'rentedOut': 50, 'remaing DVDs': 0, 'value of remaining': 0}           
    { 'id': 4, 'title': Back to the Future , 'releaseDate':2018, 'price': 20.23, 'rating': 5, 'ordered: 23, 'rentedOut': 4, 'remaing DVDs': 19, 'value of remaining': 340.15}           
    { 'id': 5, 'title': Hey!, 'releaseDate':2018, 'price': 25.23, 'rating': 4.2, 'ordered: 28, 'rentedOut': 19, 'remaing DVDs': 9, 'value of remaining': 200.95}           
    { 'id': 6, 'title': Emoji, 'releaseDate':2019, 'price': 12.43, 'rating': 3, 'ordered: 28, 'rentedOut': 13, 'remaing DVDs': 15, 'value of remaining': 165}           
    { 'id': 7, 'title': Emoji 2, 'releaseDate':2019, 'price': 17.43, 'rating': 1.9, 'ordered: 2, 'rentedOut': 1, 'remaing DVDs': 1, 'value of remaining': 15.42}           
    { 'id': 8, 'title': Mean Girls, 'releaseDate':2014, 'price': 10, 'rating': 5, 'ordered: 200, 'rentedOut': 199, 'remaing DVDs': 1, 'value of remaining': 8.85}           
    { 'id': 9, 'title': HS Musical, 'releaseDate':2014, 'price': 21.02, 'rating': 5, 'ordered: 20, 'rentedOut': 14, 'remaing DVDs': 6, 'value of remaining': 111.61}           
    { 'id': 10, 'title': HS Musical 2, 'releaseDate':2014, 'price': 21.02, 'rating': 4, 'ordered: 20, 'rentedOut': 0, 'remaing DVDs': 20, 'value of remaining': 372.04}           
        
 Bad Data case 1 (unknown text file or file that is not located in the same directory, or unsupport text file)
    Enter the name of the test inputs....
    not_a_file.txt
    Unable to open the specified name
 
Bad Data case 2 (More than one file prvided )
    Enter the name of the test inputs....
    not_a_file.txt not_a_file2.cpp
    Unable to open the specified name

 Bad Data case 3 (File found is not in the same format as testInput.txt )
    Enter the name of the test inputs....
    program3.txt
    Ten DVD Test Objects
    There was an error

 Discussion:
    The header file TMA2Question1.h contains the DVD class that is used. 
    TestInput.txt must be used in this example for the desired out come
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm> 
#include "TMA2Question1.h"
using namespace std;

int main(){
    
    string nextLine;
    string fileName;
    cout << "Enter the name of the test inputs...." << endl;
    cin >> fileName;
    ifstream textFile(fileName);

    int id =0;
    float rating = 0;
    string title = "INVALID";
    float price = 0;
    int ordered =0;
    string releaseDate = "1000";
    int rentedOut =0; 

    if (textFile.is_open()){ 
        cout<<"Ten DVD Test Objects" <<endl;
        int i =0; 
        int totalIter = 0; 
        
        // try catch is for any conversion errors if file is not in format as expected
        try{
            while (! textFile.eof() ){ 
                i++;
                totalIter ++;
                getline (textFile,nextLine);
                if(i ==1){
                    id = stoi(nextLine);
                }else if (i ==2){
                    title = nextLine;
                } else if (i ==3){
                    price = stof(nextLine);
                } else if (i ==4){
                    rating = stof(nextLine);
                } else if (i ==5){
                    ordered = stoi(nextLine);
                } else if (i ==6){
                    releaseDate = (nextLine);
                } else if (i ==7 && totalIter != 70){
                    rentedOut = stoi(nextLine);
                } else if (i==8 || totalIter ==70){
                    if (totalIter != 70){
                        id = stoi(nextLine)-1;
                    } else {
                        id = 10;
                    }
                    i =1;       

                    DVD dvd;
                    dvd.setAllDVD(id, title, price, rating, ordered, releaseDate, rentedOut);
                    dvd.print();
                    cout<< "           "<<endl;

                    id =0;
                    title = "INVALID";
                    price = 0;
                    rating = 0;
                    ordered =0; 
                    releaseDate = "1000";
                    rentedOut = 0;
                }
            }
            textFile.close();
        } catch (const exception e){
            cout<< "There was an error" << endl; 
        }
       
    } else {
            cout<< "Unable to open the specified name" << endl;
    }
    return 0;
}