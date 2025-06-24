//contructors with default arguments

#include<iostream>
using namespace std;

class Simple
{
    int data1,data2,data3;

    public :
        Simple(int a,int b=9,int c=5){//default arguments should always from right to left
        // Simple(int a=9,int b,int c=5){  this will give error as non default argument is on right of  deault argument
            data1=a;
            data2=b;
            data3=c;
        }

        void printdata()
        {
            cout<<"The value of data1 is "<<data1<<" , data2 is "<<data2<<" and data 3 is "<<data3<<"\n";
        }
};

int main()
{
    Simple s1(1),s2(1,3),s3(6,6,6);
    s1.printdata();
    s2.printdata();
    s3.printdata();

    return 0;
}