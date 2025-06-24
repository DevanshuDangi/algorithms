//virtual functions
//if i am making pointer of base class and pointing it to derived class and still wants to use functions of 
//objects of derived class using that pointer so i can use virtual functoins for it

#include<iostream>
using namespace std;
class BaseClass{
    public:
        int var_base=1;
        // void display(){ //will run default base class function
        //virtual function --> default behavior ko override krne ke liye 
        virtual void display(){ //now it will run display of derived class not of base class
            cout<<"1 Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived=2;
            void display(){
                cout<<"2 Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"2 Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};


int main()
{
    BaseClass * base_class_pointer;
    DerivedClass obj_derived;

    base_class_pointer = &obj_derived;
    base_class_pointer->display();

    BaseClass * base_class_pointer2;
    BaseClass obj_base;

    base_class_pointer = &obj_base;
    base_class_pointer->display();

    return 0;
    
}