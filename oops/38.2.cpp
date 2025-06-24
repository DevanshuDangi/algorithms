#include<iostream>
using namespace std;

class Base
{
    int data1;

    public :
        int data2;

        void setdata();
        int getdata1();
        int getdata2();

};

void Base :: setdata(){
    data1=10;
    data2=20;
}

int Base :: getdata1(){
    return data1;
}

int Base :: getdata2(){
    return data2;
}

class Derived : private Base
{
    int data3;

    public : 

        void process();
        void display();
};

void Derived :: process()
{
    setdata();//we are now usnig it here to set the data as now we cant access setdata throught main function if using derived class object
    //as now public part of base class are now private in derived class
    data3=data2*getdata1();
}

void Derived :: display()
{
    cout<<"The value of data1 is : "<<getdata1()<<"\n";//we are not wrinting data1 directly as data1 is private in base class
    cout<<"The value of data2 is : "<<data2<<"\n";
    cout<<"The value of data3 is : "<<data3<<"\n";
}

int main()
{
    Derived der;
    // der.setdata(); now we cant use this setdata becuase public part of base class is now private in drived class and you
    //cant access the private part directly
    der.process();
    der.display();

    return 0;
}