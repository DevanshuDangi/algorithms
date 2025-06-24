//friend function in cpp

#include<iostream>
using namespace std;

class Complex
{
    int a,b;
    // friend complex sumcomplex(complex o1,complex o2);

    public:
        void setNumber(int v1,int v2)
        {
            a=v1;
            b=v2;
        }

        void printNumber()
        {
            cout<<"Your number is "<<a<<" + "<<b<<"i\n";
        }

        friend Complex sumComplex(Complex o1,Complex o2);
};

Complex  sumComplex(Complex o1,Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a+o2.a),(o1.b+o2.b));

    // cout<<a<<"\n";          invalid beacuse sinec it is not a part of the class so kiska a
    // cout<<o3.a<<"\n"        this is valid
    return o3;
}

int main()
{
    Complex c1,c2;
    c1.setNumber(1,4);
    c2.setNumber(5,8);

    c1.printNumber();
    c2.printNumber();

    Complex sum;
    sum=sumComplex(c1,c2);
    sum.printNumber();

    return 0;
}
/*
properties of friend function

1. not in the scope of class i.e., this function is not in the class it is just giving acces to use it private members .
2. since it is not in the scope of the class ,it cannot be called from the object of that class , c1.sumcomplex() -> invalid.
3. can be invoked without the help of any object.
4. usually contains the objects as arguments.
5. can be deculared inside the publuc or private section of the class.
6.It can not access the members directly by their names and need object_name.member_name to access any number.
*/