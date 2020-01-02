//: TMA3Question2.cpp

/* 
 Title: TMA3Question2.cpp
 Description: Ctime Inline 
 Date: December 11, 2019
 Author: Stefan Vercillo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate proper format for documentation, test plans and comments.
    Demonstrate understanding of execution time, and arrays

 Compilation:
 (OPTION 1: Manual)
 Compile: g++ TMA3Question2.cpp -o TMA3Question2
 Execution: ./TMA3Question2
 
 (OPTION 2: Makefile)
 Execution: make run2
 Delete Compiled Object: make clean2

 Notes: in Cygwin, main must return type int
 
 Variables:
    array1,array2  - arrays to contain 10,000 doubles 
    count1, count2 - values used to fill arrays 1 and 2 respectively 
    sum - double return value of calculate function 
*/

/*
 TEST PLAN
 
 Normal case:
    Ouput is too long to show ....
    ....
    ....
    1.11977e+06
    1.10979e+06
    1.09981e+06
    1.08983e+06
    1.07984e+06
    1.06986e+06
    1.05987e+06
    1.04988e+06
    1.03989e+06
    1.02989e+06
    1.0199e+06
    1.0099e+06
    Execution Time:23 milliseconds
            
 Bad Data case: 
    There is no bad data case becuase no user input is taken
 
 Discussion:
    Median execution time of 22 milliseconds in 10 trial run. Inline functions help to reduce the overhead that can be present in funciton calls. Inline functions do not necessarily reduce the compliation time, they are however requests to the compiler that can be decline at compliation. A lot of compilation time in a funciton is taken up function calls, which can be reduced with inline functions.
*/

#include <iostream>
#include <ctime>

using namespace std;

inline int caculate() {
    
    double  array1  [10000];
    double  array2  [10000];
    double sum;
    int count1 = 99;
    int count2 = 10100;
    
    // initialize the two arrays
    for (int i=0; i <10000; i++){
        count1++;
        count2--;
        array1[i] = count1; 
        array2[i] = count2;
    }
    for (int i=0; i<10000; i++ ){
        cout << array1[i]* array2[i] <<endl;
    }
    return sum;
}

int main ()
{
	clock_t time_req;
	time_req = clock();
    int start_time = time_req / (CLOCKS_PER_SEC /1000);
    caculate();
    clock_t end_time_req;
    end_time_req = clock();
    int end_time = end_time_req / (CLOCKS_PER_SEC/1000);
    const int executionTime = end_time - start_time;

    cout<<"Execution Time:" << end_time - start_time << " milliseconds";
	return 0;
}