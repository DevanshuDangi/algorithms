#include<iostream>
using namespace std;

class complexnum{
    int a;
    int b;

    public :
        void setnum(int x,int y){
            a=x;
            b=y;
        }
        
        void getnum(){
            cout<<a<<"+"<<b<<"i\n";
        }

        void sumcmplex(complexnum o1,complexnum o2){
            a=o1.a+o2.a;
            b=o1.b+o2.b;
        }

};

int main(){
    complexnum c1,c2,c3;
    c1.setnum(1,2);
    c2.setnum(3,4);
    c3.sumcmplex(c1,c2);

    c1.getnum();
    c2.getnum();
    c3.getnum();
    
    return 0;
}