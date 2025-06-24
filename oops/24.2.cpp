#include<iostream>
using namespace std;

class Employee{
    int id;
    static int count;
    

    public : 
         void setData(void){
            cout<<"Enter the Id : ";
            cin>>id;
            count++;
         }
         
         void getData(void){
            cout<<"The Employee Id is : "<<id<<" ans this is employee number "<<count<<"\n";
         }

         static void getCount(void){
            cout<<"the value of count is : "<<count<<"\n";

            // cout<<id<<"n"
            // will give an error becuase static member function can access static members only 
         }
};

int Employee :: count;

int main(){

    Employee Harry,Rohan,Lovish;

    Harry.setData();
    Harry.getData();
    Employee :: getCount();


    Harry.setData();
    Harry.getData();
    Employee :: getCount();

    Harry.setData();
    Harry.getData();
    Employee :: getCount();

    return 0;
}