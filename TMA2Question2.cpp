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
 
 Classes: 
    
    Hen:

    Nested Classes:
        Nest:

        Nested Classes: 
            Egg:
                Constuctors:
                    There is a defualt constructor implicitly executed on object instatiation
                    setAllDVD is the secondary constructor executed explicity (open and reads file)

                Destructors:
                    There is a default destructor implicitly executed
                
                Memory Notes: 
                    A pointer is used to initialize the object and allocate memory.
                    This memory is then deleted manually

        Constuctors:
            There is a defualt constructor implicitly executed on object instatiation
            setAllDVD is the secondary constructor executed explicity (open and reads file)

        Destructors:
            There is a default destructor implicitly executed
        
        Memory Notes: 
            A pointer is used to initialize the object and allocate memory.
            This memory is then deleted manually
    

    Constuctors:
        There is a defualt constructor implicitly executed on object instatiation
        setAllDVD is the secondary constructor executed explicity (open and reads file)

    Destructors:
        There is a default destructor implicitly executed
    
    Memory Notes: 
        A pointer is used to initialize the object and allocate memory.
        This memory is then deleted manually
 
Variables:
    name -  string containing halarious name for our hen Chickovsky
    pronour - string the formal pronoun used to address our Mr.Chickovsky
    colour - string colour of the egg class
    madeOf - string stores what the hen's nest is made of
    hen - pointer to hen object
    nest - pointer to nested nest object 
    egg - pointer to nested egg object 
*/

/*
 TEST PLAN
 
 Normal case:
    Nested classes in C++:
    Contructing a HEN class
    Constructing a NEST class
    Constructing an EGG class
    I am Mr. Chickovsky
    This nest was made by  twigs
    This Egg has a  Brown colour.
    Deconstructing a HEN class
    Deconstructing a NEST class
    Deconstructing an EGG class
        
 Bad Data case (NONE): 
    There is none because this program does not take any external inputs

 Discussion:
    Only a text that is found in the same directory as this program can be used in this program.
*/

#include<iostream> 
using namespace std; 
class Hen {
 public:   
    string name ;
    string pronoun;

    Hen () { 
        cout << "Contructing a HEN class"<< endl;
    }     
    ~Hen(){
        cout << "Deconstructing a HEN class" <<endl;
    }

    void display(){
        cout<< "I am " + get_full_name() << endl;
    }
    void set_full_name(string _name, string _pronoun){
        name = _name;
        pronoun = _pronoun;
    }

    string get_full_name(){
        return pronoun + " " + name;
    }
    
    class Nest {
     public:
        string madeOf;
        Nest() { 
            cout<< "Constructing a NEST class" << endl;
        } 
        ~Nest(){
            cout<<"Deconstructing a NEST class" << endl;
        } 

        void display(){
            cout<< "This nest was made by  " + get_madeOf() <<endl;
        }

        void set_madeOf (string _madeOf){
            madeOf = _madeOf;
        }
        string get_madeOf(){
            return madeOf;
        }
        class Egg{
         public:
            string colour;
            Egg () { 
                cout << "Constructing an EGG class" <<endl;
            } 
            ~Egg (){
                cout<<"Deconstructing an EGG class" << endl;
            }

            void display(){
                cout << "This Egg has a  " + get_colour() + " colour." <<endl;;
            }
            
            void set_colour(string _colour){
                colour = _colour;
            }

            string get_colour(){
                return colour;
            }

        };
    };
};




int main() {
    cout<<"Nested classes in C++:"<< endl;
    Hen* hen = new Hen;
    Hen :: Nest* nest = new Hen :: Nest;    
    Hen :: Nest :: Egg* egg = new Hen :: Nest :: Egg;
    string name = "Chickovsky";
    string pronoun = "Mr.";
    string madeOf = "twigs";
    string colour = "Brown";

    hen->set_full_name(name, pronoun);
    hen->display();
    nest->set_madeOf(madeOf);
    nest->display();
    egg->set_colour(colour);
    egg->display();
    delete hen;
    delete nest;
    delete egg;

    return 0;
}