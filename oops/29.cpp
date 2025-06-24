//constructors

#include<iostream>
using namespace std;

class Complex
{
    int a,b;

    public : 

        // Creating a Constructor
        // Constructor is a special member function with the same name as of the class.
        //It is used to initialize the objects of its class
        //It is automatically invoked whenever an object is created
        //constructor declaration
        Complex(void);    // this is a default constructor as it take no arguments

        void display(){
            cout<<"The complex number is "<<a<<"+"<<b<<"i"<<"\n";
        }
};

Complex :: Complex(void)// this is a default constructor as it take no arguments
{
    a=0;
    b=0;

    cout<<"hello \n";
}

int main()
{
    Complex c1,c2;
    c1.display();
    c2.display();

    return 0;
}

/*
Constructors in C++

A constructor is a special member function with the same name as the class. The constructor doesn’t have a return type. Constructors are used to initialize the objects of its class. Constructors are automatically invoked whenever an object is created.

Important Characteristics of Constructors in C++

    A constructor should be declared in the public section of the class
    They are automatically invoked whenever the object is created
    They cannot return values and do not have return types
    It can have default arguments
    We cannot refer to their address

*/