//pointers to object and arrow operator in c++

#include<iostream>
using namespace std;

class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout<<"The real part is "<< real<<endl;
            cout<<"The imaginary part is "<< imaginary<<endl;
        }

        void setData(int a, int b){
            real = a;
            imaginary = b;
        }

};

int main(){
    Complex *ptr = new Complex;
    (*ptr).setData(1, 54); //is exactly same as
    (*ptr).getData(); //is as good as 
    cout<<"\n";

    Complex *ptr2 = new Complex;
    ptr2->setData(1, 54);
    ptr2->getData(); 
    cout<<"\n";

    // Array of Objects
    Complex *ptr3 = new Complex[4]; 
    ptr3->setData(1, 4); 
    ptr3->getData();
    
    (ptr3+1)->getData();

    return 0;
}
