//parameterised and default constructors

#include<iostream>
#include<cmath>
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

            // cout<<"hello \n";
        }

        void display(){
            cout<<"The complex number is "<<a<<"+"<<b<<"i"<<"\n";
        }
};

int main()
{

    //Implicit call
    Complex a(2,4);
    a.display();

    //explicit call
    Complex b=Complex(3,33);
    b.display();

    return 0;
}
