//this pointer in c++

//this is a keyword which is a pointer which points to the object which invokes the member function of class;

#include<iostream>
using namespace std;
class A{
    int a;
    public:
        void setData(int a){
            // a=a;
            //if i will write a=a then priority if set to local variable so a so a of class A is not even used so on displaying a
            //displaying it will give garbage value

            this->a = a;//so now we are using this->a resembers a of this class so now a fo class will get value of local a
            //local a is that a which is argument of the function
        }

        void getData(){
            cout<<"The value of a is "<<a<<endl;
        }
};

int main(){
    A a;
    a.setData(4);
    a.getData();
    return 0;
}


