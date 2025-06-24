#include<iostream>
using namespace std;

// initialsiztion list in contructor in cpp ->  ye bas value dene ka tareeka h




/*

Syntax for initialisation list in constructor

constructor (argument - list) : initialisation - section 
{
    assignment + other code
}




class Test
{
    int a;
    int b;

public:
    Test(int i, int j) : a(i), b(j)  //is se a mai i aa jayea and b mai j aajayega bas i.e., a(i),b(j) function ki arah work krenge

}


*/


class Test
{
    int a;
    int b;

public:

    // Test(int i, int j) : a(i), b(i)    //this will work
    // Test(int i, int j) : a(i), b(i+j)  //this will also work
    // Test(int i, int j) : a(i), b(a+j)  //this will also work

    // Test(int i, int j) : b(j), a(i+b)  //this will will garbage value of a   as in class test a is made before b for 
    //first we have to assign value to a then to b so it will assign value to a first i.e., a=b+i and since b is not 
    //initilaised before so it will take  garbage value but it will give output like this--
    // Constructor executed
    // Value of a is 32768
    // Value of b is 6

    Test(int i, int j) : a(i), b(a+j) 
    
    {
        cout << "Constructor executed"<<endl;
        cout << "Value of a is "<<a<<endl;
        cout << "Value of b is "<<b<<endl;
    }

    // this will also work
    // Test(int i, int j) : a(i)
    
    // {
    //     b=j;

    //     cout << "Constructor executed"<<endl;
    //     cout << "Value of a is "<<a<<endl;
    //     cout << "Value of b is "<<b<<endl;
    // }


    // this will also work
    // Test(int i, int j)
    
    // {
    //     a=i;
    //     b=j;

    //     cout << "Constructor executed"<<endl;
    //     cout << "Value of a is "<<a<<endl;
    //     cout << "Value of b is "<<b<<endl;
    // }

    
};

int main()
{
    Test t(4, 6);

    return 0;
}

