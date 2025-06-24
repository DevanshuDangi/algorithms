//virtual base class in c++

//we will be saved from abiguilty and repetetion

/*

Inheritance :

student-->test
stuent-->sports
test-->result
sports-->result


*/

#include<iostream>
using namespace std;

class Student
{
    protected : 
        int roll_no;

    public : 
        void set_rollnumber(int a)
        {
            roll_no=a;
        }

        void print_number()
        {
            cout<<"Your roll number is : "<<roll_no<<"\n";
        }

};

class Test : virtual public Student
{
    protected : 
        float maths,physics;

    public : 
        void set_marks(float m1,float m2)
        {
            maths=m1;
            physics =m2;
        }

        void print_marks()
        {
            cout<<"your maths marks are : "<<maths<<"\n";
            cout<<"your physics marks are : "<<physics<<"\n";

        }

};

class Sports : virtual public Student
{
    protected : 
        float score;
    
    public :
    void set_score(float f1)
    {
        score=f1;
    }

    void print_score()
    {
        cout << "Your Sports score is : " << score << "\n";
    }
};

class Result : public Test , public Sports
{
    protected : 
        float percentage;
    
    public : 
        void display()
        {
            print_marks();
            print_score();
            percentage=(maths+physics+score)/3 ;

            cout << "The final percentage is : " << (maths+physics+score)/3 << "\n";
        }
};

int main()
{

    Result harry;
    harry.set_rollnumber(134);

    harry.set_marks(97.3,89.2);
    harry.set_score(99.5);

    harry.display();

    return 0;
}


//without writing virtual while inheriting class it will show and error of ambiguyuity
