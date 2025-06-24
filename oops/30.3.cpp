#include<iostream>
#include<math.h>

using namespace std;

class Point
{

    // void distance(Point , Point );

    public : 
    int x,y;
        Point(int a,int b)
        {
            x=a;
            y=b;
        }

        void display(){
            cout<<"The point is ("<<x<<","<<y<<")\n";
        }
};

void distance(Point a,Point b){
    cout<<sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))<<"\n";
}

int main()
{

    Point a(2,3),b(22,32);
    a.display();
    b.display();

    distance(a,b);

    return 0;
}