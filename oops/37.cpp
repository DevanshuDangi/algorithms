#include<iostream>
using namespace std;

class Employee
{
    public :   
        int id;
        int salary;

        Employee(int ID){
            id=ID;
            salary=34;
        }

        Employee(){

        }

};

// Note:

//     Default visibility mode is private
//     Public Visibility Mode: Public members of the base class becomes Public members of the derived class
//     Private Visibility Mode: Public members of the base class become private members of the derived class
//     Private members are never inherited

// An example program is shown below to demonstrate the concept of inheritance.





//syntax for inheritance
/*
 // Derived Class syntax
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc...
}
*/

//class Programmer : private  Employee
//class Programmer :  Employee
// class Programmer : public Employee
// class Programmer : protected Employee
//these are 4 ways to do it (and in default that is in 2nd one the default is private)

// Creating a Programmer class derived from Employee Base class
class Programmer : public Employee
{
    public : 
        int languagecode;

        Programmer(int ipID){
            id=ipID;
            languagecode =9;
            salary = 240;
        }

        void getData(){
            cout<<"the ID is : "<<id<<"\n";
        }
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;


    Programmer skillF(10);
    cout << skillF.languagecode<<endl;
    cout << skillF.salary<<endl;
    cout << skillF.id<<endl;
    skillF.getData();
    return 0;
}
