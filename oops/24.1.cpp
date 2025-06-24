//static data members and methods in c++

#include<iostream>
using namespace std;

class Employee{
   public : 
    int id;
    // int count;

    static int count;
    //since we dont have to give count to every object if this class we just want one count for the whole class

    //we dont have to initilise static variable by 0  it is already initiliased by 0 when creating when it is static

    //static int count =1000
    // if we want to iniilaseit with 1000 then this will give syntax error
    

    public : 
         void setData(void){
            cout<<"Enter the Id : ";
            cin>>id;
            count++;
         }
         
         void getData(void){
            cout<<"The Employee Id is : "<<id<<" ans this is employee number "<<count<<"\n";
         }
};

int Employee :: count;//default value is 0

// int Employee :: count =1000 ;
// this is the correct way to initialsize count with 1000

int main(){

    Employee Harry,Rohan,Lovish;

    //count is the static data member of the  class Employee

    Harry.setData();
    Harry.getData();

    Harry.setData();
    Harry.getData();

    Harry.setData();
    Harry.getData();

   //  cout<<Harry.count<<"\n";
   Employee devil ;
   devil.setData();

   cout<<Harry.count<<"\n";
   cout<<devil.count<<"\n";

   //both will give smae answer 4

    return 0;
}