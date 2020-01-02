// Write a program to manage DVD rental in a video rental store. Create an abstract data type that represents a DVD in this store. Consider all the data and operations that may be necessary for the DVD type to work well within a rental management system. Include a print() member function that displays all the information about the DVD. Test your data type by creating an array of ten DVD instances and filling them using information read from a test input file that you create. Display the DVD information.


#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class DVD {
    public:
        int id;

        // rating of movie out of 5
        float rating;

        // title of movie
        string title;

        // Customer facing price in CAD 
        float price;

        // ordered (number of DVDs that were ordered and should be theoretically in the store)
        int ordered;

        // year that the DVD was realseds
        string releaseDate;

        // number of people that DVD is currenly rented out to
        int rentedOut;
    
    // default contstructor
    DVD() {
        id =0;
        title = "INVALID";
        price = 0;
        rating = 0;
        ordered =0; 
        releaseDate = "1000";
        rentedOut = 0;
    }

    // parameterized constructor 
    void setAllDVD(int _id, string _title, float _price, float _rating,
    int _ordered, string _releaseDate, 
    int _rentedOut){
        id = _id;
        title = _title;
        price = _price;
        rating = _rating;
        ordered = _ordered;
        releaseDate = _releaseDate;
        rentedOut = _rentedOut;
    }
    // if DVD is ordered then this function is to be run
    void submitOrder (){
        ordered ++;
    }
    // if another of this particular DVD is rented out then this is to be run
    void rentDVD (){
        rentedOut ++;
    }
    // if the price of the DVD is 
    void changePrice (float newPrice) {
        price = newPrice;
    }
    int getNumberOfDVDRemaining(){
        return ordered - rentedOut;
    }
    /* calculates the potential store revenue from DVD's remaining in based 
    on the current store price the store and ommits the HST that is present 
    in the price caclulation
    */
    float valueOfRemainingDVD(int HSTpercent) {
        return roundf(price*(ordered - rentedOut) / (HSTpercent + 100)*100*100)/100 ;
    } 

    void print() {

        cout << "{ 'id': " << id << ", 'title': " << title  << ", 'releaseDate':" << releaseDate 
        << ", 'price': " << price << ", 'rating': " << rating
        << ", 'ordered: " << ordered
        << ", 'rentedOut': " 
        << rentedOut << ", 'remaing DVDs': " << 
        getNumberOfDVDRemaining() << ", 'value of remaining': "  << valueOfRemainingDVD(13) <<
        '}';
    }
    
    // All the getter functions
    int getid(){ 
        return id;
    }
    int getordered(){ 
        return ordered;
    }
    int getrentedOut(){ 
        return rentedOut;
    }
    string getTitle(){ 
        return title;
    }
    string getreleaseDate() {
        return releaseDate;
    }
    float getRating(){
        return rating;
    }
    float getprice(){
        return price;
    }

};