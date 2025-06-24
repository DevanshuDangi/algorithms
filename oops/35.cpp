//destrucotr in c++
#include<iostream>
using namespace std;

 
int count=0;

class num{
    public:
        //creating a constructor
        num(){
            count++;
            cout<<"This is the time when constructor is called for object number"<<count<<endl;
        }

        //creating a destructor
        // Destructor never takes an argument nor does it return any value
        ~num(){
            cout<<"This is the time when my destructor is called for object number"<<count<<endl;
            count--;
        }
};

int main(){
    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    num n1;
    {
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num n2, n3;
        cout<<"Exiting this block"<<endl;
    }//while exiting the block the destructor will automatically called and destruct all the objects created inside this block

    cout<<"Back to main"<<endl;
    return 0;
}
