#include<iostream>
using namespace std;



class B{
    public:
        void say(){
            cout<<"Hello world"<<endl;
        }
};

class D: public B{
    int a;
    // D's(Derived) new say() method will override base class's say() method
    public:
        void say()
        {
            cout << "Hello my beautiful people" << endl;
        }
};

class D2: public B{
    int a;
    // since no new say method so will use say method of base class 
    
};
class E: public D{
    int a;
    // since no new say method so will use say method of last base class 
    
};

class F : public D2{
    int a;
};


int main(){
    // Ambibuity 2
    B b;
    b.say();

    D d;
    d.say();

    D2 d2;
    d2.say();

    E e;
    e.say();

    F f;
    f.say();

    return 0;
}

