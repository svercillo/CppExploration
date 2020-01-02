//: TMA3Question3.cpp

/* 
 Title: TMA3Question3.cpp
 Description: Shape Classes  
 Date: December 11, 2019
 Author: Stefan Vercillo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate proper format for documentation, test plans and comments.
    Demonstrate understanding of basic c++ classes, inheritance,
    and function and operator overloading.


 Compilation:
 (OPTION 1: Manual)
 Compile: g++ TMA3Question3.cpp -o TMA3Question3
 Execution: ./TMA3Question3
 
 (OPTION 2: Makefile)
 Execution: make run3
 Delete Compiled Object: make clean3

 Notes: in Cygwin, main must return type int
 
 Classes: 

    POINT: 
        Description: 
            Used to represent a coordinate point on the cartesian plane.

        Methods:
            Point class has two constructors, one is used for null points
            
        Operator Overloading:
            For two points, the sign "+", is used to add points, "-" is used to subtract (vector addition and subtraction)
            The "*" is used to find the slope of two points
            The || is used to find the absolute value of distance between two points

    SHAPE:
        Description:
            Used as the base/ parent class for Triangle, Circle and Rectangle.
            Circumference, area and the coordinates for a surrounding boundary rectange is calculated here

    TRIANGLE:

        Constructor:  
            Used to initalized the 3 points of the triangle and bool indicating if its a triangle or not
        
        Function Overloading:
            
            Area is calculated here taking the parameter bool is_triangle. This function recreates the triangle in a cartesian in a way which is easier to calculate area
            
            Circumference is also overloaded taking the parameter is_triangle again.
            
            Display - outputs to the console using the overloaded functions above
 
    CIRCLE:

        Constructor:  
            Used to initalized point A which is the center of the circle and the radius r
        
        Function Overloading:
            
            Area is calculated here taking the parameter of in radius.
            This is calculated using the equation area = π * r^2

            Circumference is also overloaded taking the parameter radius again.

            Boundary Rectangle points generator function is also overloader taking paramter radius.

            Display - outputs to the console using the overloaded functions above

    RECTANGLE:

        Constructor:
            Used to initalized all 4 points of the rectangle


Structs: 

    PARALLELOGRAM:
        
        Description: 
            Basic struct to contain the four points of a parallelogram.
        
 
Variables:

    (   in main() function  )
    String - shape holds the type of shape, t, c , or r
    point_array - contains all the points for the shape
    letters - contais letters used in for loop to indicate which point 
            coordinates are to be entered for 
    int x1, y1 - represent the integers of the coordinates for each point
    rectangle, triangle, circle - represent their respective derived class objects.
    radius - represents radius for circle entered
                
*/

/*
 TEST PLAN
 
 Normal case 1 Triangle:
    ./TMA3Question3
    Enter the name of the shape you would like to build:
    c (for circle), t (for triangle), r (for rectangle)
    t

    (All points that are entered must be integer values)

    Enter a point A:
    x value = 0
    y value = -2

    Enter a point B:
    x value = -15
    y value = 8

    Enter a point C:
    x value = 12
    y value = 3

    This shape is a Triangle:
    Circumference = 58.4868
    Area = 97.5
    Surrounding box has the following coordinates:  (-15, -2),  (-15, 8),  (12, 8),  (12, -2)%

 Normal case 2 Rectangle:
    ./TMA3Question3
    Enter the name of the shape you would like to build:
    c (for circle), t (for triangle), r (for rectangle)
    r

    (All points that are entered must be integer values)

    Enter a point A:
    x value = -1
    y value = -1

    Enter a point B:
    x value = 2
    y value =
    3

    Enter a point C:
    x value = -2
    y value = 1

    Enter a point D:
    x value = 3
    y value = 1

    This shape is a Rectangle:
    Circumference = 13.4164
    Area = 10
    Surrounding box has the following coordinates:  (-2, -1),  (-2, 3),  (3, 3),  (3, -1)%

Normal case 3 Circle:
    ./TMA3Question3
    Enter the name of the shape you would like to build:
    c (for circle), t (for triangle), r (for rectangle)
    c

    (All points that are entered must be integer values)

    Enter a point A:
    x value = -13
    y value = 2

    Enter the radius of the circle (must be a postive int):
    4

Bad Data case 1: one of the availble shapes was not selected 
    ./TMA3Question3
    Enter the name of the shape you would like to build:
    c (for circle), t (for triangle), r (for rectangle)
    g
    Error: Invalid shape%

Bad Data case 2: non-integer value is given for a x or y value of a point 
    ./TMA3Question3
    Enter the name of the shape you would like to build:
    c (for circle), t (for triangle), r (for rectangle)
    t

    (All points that are entered must be integer values)

    Enter a point A:
    x value = asdf;
    y value =
    (All points that are entered must be integer values)

    Enter a point B:
    x value = y value =
    (All points that are entered must be integer values)

    Enter a point C:
    x value = y value =
    This shape is a Triangle:
    Circumference = 0
    Area = 0
    Surrounding box has the following coordinates:  (0, 0),  (0, 0),  (0, 0),  (0, 0)

Bad Data case 3: non-integer value is given for radius of circle
    ./TMA3Question3
    Enter the name of the shape you would like to build:
    c (for circle), t (for triangle), r (for rectangle)
    c

    (All points that are entered must be integer values)

    Enter a point A:
    x value = e
    y value =
    Enter the radius of the circle (must be a postive int):

    This shape is a Circle:
    Circumference = 0
    Area = 0
    Surrounding box has the following coordinates:  (0, 0),  (0, 0),  (0, 0),  (0, 0)

Bad Data case 4: 4 points given under rectangle selection do not form a rectangle
    ./TMA3Question3
    Enter the name of the shape you would like to build:
    c (for circle), t (for triangle), r (for rectangle)
    r

    (All points that are entered must be integer values)

    Enter a point A:
    x value = 1
    y value = 1

    (All points that are entered must be integer values)

    Enter a point B:
    x value = 1
    y value = 1

    (All points that are entered must be integer values)

    Enter a point C:
    x value = 1
    y value = 1

    (All points that are entered must be integer values)

    Enter a point D:
    x value = 1
    y value = 1

    This shape is a Rectangle:
    Circumference = 0
    Area = 0
    Surrounding box has the following coordinates:  (1, 1),  (1, 1),  (1, 1),  (1, 1)%




************************************
 Discussion:
    For the boundary rectangle function, the enclosing of any shape was implied to be inclusive (as it was not explictly stated in the question). 
    This means that for any shape, the boundary rectangle can include one or more points of the shape.
    
    Also for this program there is the restriction that all points must be integeral values.
    It was not stated in the question how the points should be entered by the user so this was implicitly assumed.

    There is not restriction on how the rectangle is rotated and the rectangle can be rotated at any angle, so long as it's points have an integral value
*/

#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
#include <stdlib.h>    /*         */
#include <math.h>      /* sqrt    */
#include <cmath>       /* asin()  */
#include <cstdlib>     /* abs()    */
#define _USE_MATH_DEFINES


using namespace std; 
  
class Point { 
    // this is assumed that x and y values must be stored as ints
    public:
    int x, y;
    bool null;

    // default constructor (used for null points)
    Point(){
        // x and y in practically should not have these values
        null = true;
        
    }
    // explicit constructor
    Point (int _x, int _y ){
        x= _x;
        y = _y;
        null = false;
    }  
    Point operator + (Point point){
        Point newPoint;
        newPoint.x  = point.x + x;
        newPoint.y = point.y + y;
        return newPoint;
    }
    Point operator - (Point point){
        Point newPoint;
        newPoint.x  = point.x - x;
        newPoint.y = point.y - y;
        return newPoint;
    }

// returns the absolute value of distance between two points
    float operator || (Point point){
        Point newPoint;
        Point newPointB;
        newPoint.x = x;
        newPoint.y = y;
        newPointB = absolute(point - newPoint);
        return sqrt (newPointB.x*newPointB.x + newPointB.y*newPointB.y);
    }
// returns the slope of between two points
    float operator * (Point point){
        if (( x - point.x) != 0){
            float h = (y-point.y);
            float w = (x - point.x);
            return h/w;
        } else {
            return -9999;
        }
    }
    Point absolute (Point P){
        P.x = abs(P.x);
        P.y = abs(P.y);
        return P;
    }
    void print(){
        cout << " (" << x << ", " << y << ")";
    }
};

struct Parallelogram {
    Point one;
    Point two;
    Point three;
    Point four;

};

class Shape {

    public:
    Point A;
    Point B;
    Point C;
    Point D;
    bool istriangle;
    string shape;
    Point array [4];

    // no constructor, default or otherwise is required

    float get_circumference() {   
        float farr [4];
        farr[1] = A || B;
        farr[2] = A || C;
        farr[3] = A || D;

        // find which point is furthest away from the first point (in a rectangle this is the point which will not be joined to the starting point)
        int longest;
        if (farr[1] > farr[2]  && farr[1] > farr[3]){
            longest = 1;
        } else if (farr[2] >farr[1] && farr[2] > farr[3]){
            longest = 2;
        } else {
            longest = 3;
        }
        
        float area =1;
        float length =0;
        float width =0;
        for (int i=1; i<sizeof(array)/sizeof(array[0]); i++){
            if (i == longest){
                continue;
            }
            if (length ==0)
                length = farr[i];
            else {
                width = farr[i];
            }
        }
        return 2 * (length + width);
    }
    float get_area (){ 
        float farr [4];
        farr[1] = A || B;
        farr[2] = A || C;
        farr[3] = A || D;
        
        // find which point is furthest away from the first point (in a rectangle this is the point which will not be joined to the starting point)
        int longest;
        if (farr[1] > farr[2]  && farr[1] > farr[3]){
            longest = 1;
        } else if (farr[2] >farr[1] && farr[2] > farr[3]){
            longest = 2;
        } else {
            longest = 3;
        }
        
        float area =1;
        for (int i=1; i<sizeof(array)/sizeof(array[0]); i++){
            if (i == longest){

                continue;
            }
            area *= farr[i];
        }
        
  
        // cout << "The area is " << area <<endl;
        return area;
    } 

    Parallelogram boundary_rectangle(){
        
        int by = INT_MIN;
        int bx = INT_MIN;
        int sy = INT_MAX;
        int sx = INT_MAX;
        int i =0;
        
        int sizeofArr;
        if (istriangle) sizeofArr = 3;
        else sizeofArr =4;
        // cout << " " << endl;
        
        for (; i<sizeofArr; i++){
            if (array[i].x > bx){
                bx = array[i].x;    
            }
            if (array[i].y > by){
                by = array[i].y;
            }
            if (array[i].x < sx){
                sx = array[i].x;
            }
            if (array[i].y <sy){
                sy = array[i].y;
            }
        }

        Point a (sx, sy);
        Point b (sx, by);
        Point c (bx, by);
        Point d (bx, sy);
        
        Parallelogram rectangle;
        rectangle.one = a;
        rectangle.two = b;
        rectangle.three = c;
        rectangle.four = d;

        return rectangle;
    }
   
    void display (){
        Parallelogram  parallel ;
        parallel = boundary_rectangle(); 
        cout << "This shape is a " << shape << ":" <<endl; 
        cout << "   Circumference = " << get_circumference() << endl;
        cout << "   Area = " << get_area() <<endl;
        cout << "   Surrounding box has the following coordinates: "; 
        parallel.one.print();  
        cout << ", ";
        parallel.two.print();
        cout << ", ";
        parallel.three.print();
        cout << ", ";
        parallel.four.print();

    }   
};


// DERIVED CLASSES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Triangle : public Shape {
    public:
    float side1, side2, side3;

    Triangle (Point _A, Point _B, Point _C){
        A = _A;
        B = _B;
        C = _C;
        array[0] = A; 
        array[1] = B; 
        array[2] = C; 
        shape = "Triangle";
        
        Point D;
        array[3] = D; 
        istriangle = true;
    }

    float get_area(bool is_triangle){  
        /* Heron's formula:
        Area = \sqrt{ s(s-a)(s-b)(s-c) }        
            where s = circumference/ 2
            where a,b,c are sides the sides of the triangle
        */

        float s = get_circumference(true) /2;
        return sqrt( s * (s - side1) * (s-side2) * (s-side3));
    }

    float get_circumference(bool is_triangle){
        side1 = A || B;
        side2 = B || C;
        side3 = A || C;
        return side1 + side2 + side3;
    }
    
    void display (){
        Parallelogram  parallel ;
        parallel = boundary_rectangle(); 
        cout << "This shape is a " << shape << ":" <<endl; 
        cout << "   Circumference = " << get_circumference(istriangle) << endl;
        cout << "   Area = " << get_area(istriangle) <<endl;
        cout << "   Surrounding box has the following coordinates: "; 
        parallel.one.print();  
        cout << ", ";
        parallel.two.print();
        cout << ", ";
        parallel.three.print();
        cout << ", ";
        parallel.four.print();

    }   
};


class Circle : public Shape {
    public:
    int r;
    Point center;

    Circle (Point _center, int _r ){
        r = _r;
        center = _center;
        istriangle = false;
        shape = "Circle";
    }

    float get_area(int r){
        return M_PI * r *r;
    }

    float get_circumference(int r){ 
        return M_PI * 2 * r;
    }
    
    Parallelogram boundary_rectangle (int r){
        Point a;
        Point b;
        Point c;
        Point d;
        
        a.x = center.x + r;
        a.y = center.y +r;
        b.x = center.x -r;
        b.y = center.y +r;
        c.x = center.x +r;
        c.y = center.y -r;
        d.x = center.x -r;
        d.y = center.y -r;

        Parallelogram rectangle;
        rectangle.one = a;
        rectangle.two = b;
        rectangle.three = c;
        rectangle.four = d;

        return rectangle;
    } 
    
    void display (){
        Parallelogram  parallel ;
        parallel = boundary_rectangle(r); 
        cout << " "<< endl;
        cout << "This shape is a " << shape << ":" <<endl; 
        cout << "   Circumference = " << get_circumference(r) << endl;
        cout << "   Area = " << get_area(r) <<endl;
        cout << "   Surrounding box has the following coordinates: "; 
        parallel.one.print();  
        cout << ", ";
        parallel.two.print();
        cout << ", ";
        parallel.three.print();
        cout << ", ";
        parallel.four.print();

    }  
};

class Rectangle : public Shape {

    public:

    Rectangle(Point _A, Point _B, Point _C, Point _D){
        A = _A;
        B = _B;
        C = _C;
        D = _D;
        array[0] = A; 
        array[1] = B; 
        array[2] = C; 
        array[3] = D; 
        
        shape = "Rectangle";
        istriangle = false;
    }
};

int main() {
    int x =3;
    int y =2;
    int z =1;
    
    cout << "Enter the name of the shape you would like to build:" <<endl;
    cout << "c (for circle), t (for triangle), r (for rectangle)" <<endl;

    string shape;
    cin>> shape;

    Point point_array [4];


    if (shape != "t" && shape != "r" && shape != "c" ) {
        cout << "Error: Invalid shape";
        return 0;
    }

    int x1;
    int y1;
    string letters [4] = {"A", "B", "C", "D"};
    cout << " " <<endl;
    for (int j=0; j<4; j ++){
        if (shape == "t" && j>2) {
            continue;
        } else if (shape == "c" && j>0){
            continue;
        }
        cout <<"(All points that are entered must be integer values)" << endl << endl;
        cout << "Enter a point " + letters[j] + ":" <<endl;
        cout<< "x value = ";
        cin >> x1;
        cout<< "y value = ";
        cin>>y1;
        cout<<endl;
        Point point (x1, y1);
        point_array[j] = point;
    }

    if (shape == "r"){
        Rectangle rectangle (point_array[0], point_array[1], point_array[2], point_array[3]);
        rectangle.display();
    } else if (shape == "t"){
        Triangle triangle (point_array[0], point_array[1], point_array[2]);
        triangle.display();
    } else {
        int radius;
        cout << "Enter the radius of the circle (must be a postive int):" <<endl;
        cin >> radius;
        Circle circle (point_array[0], radius);
        circle.display();
    } 
    return 0;
} 