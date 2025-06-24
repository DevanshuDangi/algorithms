//ambiguity resolution in inheritance

#include<iostream>
using namespace std;

class Base1{
    public:
        void greet(){
            cout<<"How are you?"<<endl;
        }
};

class Base2{
    public:
        void greet()
        {
            cout << "Kaise ho?" << endl;
        }
};


class Derived : public Base1, public Base2{
   int a;
   public:
    void greet(){
        Base2 :: greet();  //if we dont write this line then will not show any error also now it is an empty function so it wont work
        }//if we dont write this function then will show error as greet is ambigous as we cant say from which we have to take greet from 
};


int main(){
  // Ambibuity 1
     Base1 base1obj;
     Base2 base2obj;
     base1obj.greet();
     base2obj.greet();
     Derived d;
     d.greet();

    return 0;
}

