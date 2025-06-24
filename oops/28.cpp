#include<iostream>
using namespace std;

class c2;

class c1
{
    int val;

    friend void exchange(c1 &,c2 &);

    public : 
        void setval(int v)
        {
            val=v;
        }

        void display()
        {
            cout<<"value of c1 is : "<<val<<"\n";
        }
};


class c2
{
    int val2;

    friend void exchange(c1 &,c2 &);

    public :
        void setdata(int x)
        {
            val2=x;
        }

        void display()
        {
            cout<<"The value of c2 is : "<<val2<<"\n";
        }
};

void exchange(c1 & x,c2 & y){
    swap(x.val,y.val2);
}


int main(){
    c1 x;
    c2 y;

    x.setval(3);
    y.setdata(11);

    x.display();
    y.display();

    exchange(x,y);

    x.display();
    y.display();
    
    return 0;
}