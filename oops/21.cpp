#include<iostream>
using namespace std;

class Employee
{
    private : 
        int a,b,c;
    
    public:
        int d,e;

        void setData(int a1,int b1,int c1);

        void getData()
        {
            cout<<"the value of a is "<<a<<"\n";
            cout<<"the value of b is "<<b<<"\n";
            cout<<"the value of c is "<<c<<"\n";
            cout<<"the value of d is "<<d<<"\n";
            cout<<"the value of e is "<<e<<"\n";
        }
};

void Employee :: setData(int a1,int b1,int c1){
    a=a1;
    b=b1;
    c=c1;
}

int main(){

    Employee Harry;
    Harry.setData(1,2,4);
    Harry.getData();

    Harry.d=4;
    Harry.e=9;
    Harry.getData();

    // Harry.a=7 :: this will give error because a,b,c are private so we cant access it without using its class

    return 0;
}
