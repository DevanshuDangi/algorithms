//pointers to derived class


#include<iostream>
using namespace std;
class BaseClass{
    public:
        int var_base;
        void display(){
            cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived;
            void display(){
                cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};

int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived; // Pointing base class pointer to derived class object

    base_class_pointer->var_base = 34;
    // base_class_pointer->var_derived= 134; // Will throw an error
    //because since the pointer is from base calss so it will do only those function or access only those members
    // of derived class which are inherited from base class as the pointer is of base class
    //since we decided in run time which display function to call
    //hence called run time polymorphism

    base_class_pointer->display();// since the pointer is of base class so it will use display function of base class only 
    //so it will do late binding as it is bindin with the base class
    //hence called run time polymorphism

    base_class_pointer->var_base = 3400; 
    base_class_pointer->display();

    DerivedClass * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 9448;
    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display();
    // since the pointer is of base class so it will use display function of derived class only 
    //so it will do late binding as with the derived class only
    //since we decided in run time which display function to call
    //hence called run time polymorphism

    return 0;
}
