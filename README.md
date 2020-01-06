# CPP Exploration
This contains all the work and assignments from the Comp 206 C++ data structures course.
This work is for an equivalent course for ECE 150 at the University of Waterloo.

ASSIGNMENT A3:

Write a program in which you create a const whose value is determined at runtime by reading the time when the program starts (hint: use the <ctime> standard header). In a separate function, have the program create two arrays of 10,000 doubles. 
Initialize the first array with sequential integral values starting with 100, and initialize the second array with the same numbers, but in reverse order (i.e., the first array would contain 100, 101, 102… while the second array contains 10,099, 10,098, 10,097…). Loop through both arrays using a single loop, and multiply the corresponding array elements from each array together and display the result. Read the time when the program completes the multiplication, and compute and display the elapsed time. Do not use inline functions in this program.
  
Rewrite program 1 using an inline function to perform the calculation. In the test plan for this program (actual results section), compare the time required by this program to execute against the time required by the first (non-inline) program.
Write a program that creates a class hierarchy for simple geometry.
  
Start with a Point class to hold x and y values of a point. Overload the >> operator to print point values and the + and – operators to add and subtract point coordinates (hint: keep x and y separate In the calculation).
Create a base class Shape which will form the basis of your shapes. The Shape class will contain functions to calculate area and circumference of the shape, plus provide the coordinates (Points) of a rectangle that encloses the shape (a bounding box). These will be overloaded by the derived classes as necessary. Create a display() function that will display the name of the class plus all stored information about the class (including area, circumference, and bounding box).

Build the hierarchy by creating the Shape classes Circle, Square, and Triangle. For these derived classes, create default constructors and constructors whose arguments can initialize the shapes appropriately using the correct number of Point objects (i.e., Circle requires a Point center and a radius; Square requires four Point vertices, while Triangle requires three Point vertices).

In main(), create one instance each of the following: a Circle with a radius of 23, a Square with sides 25, and a Triangle with sides 10, 20, 30. Define all of them so that the origin (0,0) is somewhere within each object. Display the information from each object.


ASSIGNMENT B2:
C++ Programs

Write a program to manage DVD rental in a video rental store. Create an abstract data type that represents a DVD in this store. Consider all the data and operations that may be necessary for the DVD type to work well within a rental management system. Include a print() member function that displays all the information about the DVD. Test your data type by creating an array of ten DVD instances and filling them using information read from a test input file that you create. Display the DVD information.

Write a program in which you create a Hen class. Inside this class, nest a Nest class. Inside Nest, place an Egg class. Each class should have a display() member function. For each class, create a constructor and a destructor that prints an appropriate message when it is called. In main(), create an instance of each class using new and call the display() function for each one. After calling display(), free the storage using delete.

Write a program in which you create a Text class that contains a string object to hold the text of a file. Give it two constructors: a default constructor and a constructor that takes a string argument that is the name of the file to open. When the second constructor is used, open the file and read the contents of the file into the string member object. Add a member function contents() to return the string so that you can display it. In main(), open a file using Text and display the contents.

ASSIGNMENT C1:

C++ Programs
Write a program that opens a file and counts the whitespace-separated words in that file.
Write a program that opens a (text) file, and displays the contents of that file one line at a time. After a line has been displayed, the program should wait for the user to press the key before displaying the next line in the file.
Write a program that uses two nested for loops and the modulus operator (%) to detect and print the prime numbers from 1 to 10,000. (Prime numbers are natural numbers that are not evenly divisible by any other number except for themselves and one). Display all the primes found.

Write a program that creates an array of 100 string objects. Fill the array by having your program open a (text) file and read one line of the file into each string until you have filled the array. Display the array using the format “line #: <string>,” where # is the actual line number (you can use the array counter for this value) and <string> is the stored string.
Create a makefile for one of the exercises in this assignment (your choice) that allows the user to type make for a production build of the program and make debug for a build of the program that includes debugging information.

