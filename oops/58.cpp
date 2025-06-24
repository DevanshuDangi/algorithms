//abstract class and pure virtual function

/*

Pure Virtual Functions in C++

Pure virtual function is a function that doesn’t perform any operation and the function is declared by assigning 
the value 0 to it. Pure virtual functions are declared in abstract classes.

// display is now a pure virtial function so now in every derived class of base 
//class you must have to make display function else will throw an error if you run display in a 
//derived class not havin display function

Abstract Base Class in C++

abstract class is that class which we make sololy to make other derived class from it therefore it has one pure virtual function 

Abstract base class is a class that has at least one pure virtual function in its body. The classes which are 
inheriting the base class must need to override the virtual function of the abstract class otherwise compiler will 
throw an error.

To demonstrate the concept of abstract class and pure virtual function an example program is shown below

*/


//virtual function example

#include<iostream>
#include<string>
using namespace std;

/*
Rules for virtual functions

    They cannot be static
    They are accessed by object pointers
    Virtual functions can be a friend of another class
    A virtual function in the base class might not be used.
    If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class

*/


class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r){
            title =  s;  
            rating = r;
        }
        virtual void display() =0; //donothing->function  --  now this is a pure virtual function
        // display is now a pure virtial function so now in every derived class of base 
        //class you must have to make display function else will throw an error if you run display in a 
        //derived class not havin display function

};


class CWHVideo: public CWH
{
    float videoLength;
    public:
        CWHVideo(string s, float r, float vl): CWH(s, r){
            videoLength = vl;
        }
        void display(){
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
            cout<<"Length of this video is: "<<videoLength<<" minutes"<<endl;
        }
};    


class CWHText: public CWH
{
    int words;
    public:
        CWHText(string s, float r, int wc): CWH(s, r){
            words = wc;
        }
     void display(){
      cout<<"This is an amazing text tutorial with title "<<title<<endl;
      cout<<"Ratings of this text tutorial: "<<rating<<" out of 5 stars"<<endl;
      cout<<"No of words in this text tutorial is: "<<words<<" words"<<endl;
         }
};

class CC: public CWH
{
    public :
        CC() : CWH("hi",2){

        }
};


int main(){
    string title;
    float rating, vlen;
    int words;

    // for Code With Harry Video
    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    CWHVideo djVideo(title, rating, vlen);
    djVideo.display();

    cout<<"\n";

    // for Code With Harry Text
    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;
    CWHText djText(title, rating, words);
    djText.display();
    
    cout<<"\n";

    CWH* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;

    tuts[0]->display();
    cout<<"\n";
    tuts[1]->display();
    cout<<"\n";

    // CC obj;
    // obj.display();
    //now this will throw an error because display is now a pure virtial function so now in everu derived class of base 
    //class you must have to make display function


    return 0;
}
