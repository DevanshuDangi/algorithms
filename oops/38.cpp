//deep dive into single inheritance

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


class Derived : public Base
{
    int data3;

    public : 

        void process();
        void display();
};

void Derived :: process()
{
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
    der.setdata();
    der.process();
    der.display();

    return 0;
}