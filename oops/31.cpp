//constructor overloading

#include<iostream>
using namespace std;

class Complex
{
    int a,b;

    public : 
        //contructor declaration
        Complex(int x,int y) //this is a paramterised contructor as it takes 2 parameters
        {
            a=x;
            b=y;

        }

        //contructor declaration with other parameters
        Complex(int x) //this is a paramterised contructor as it takes 1 parameters
        {
            a=x;
            b=0;
        }

        //contructor declaration 
        Complex() //this is a default contructor as it takes no parameters
        {
            a=0;
            b=0;
        }

        

        void display(){
            cout<<"The complex number is "<<a<<"+"<<b<<"i"<<"\n";
        }
};


int main()
{

    Complex c1,c2(2,5),c3(3);

    c1.display();
    c2.display();
    c3.display();


    return 0;
}