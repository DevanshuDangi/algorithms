// OOPs - Classes and objects

// C++ --> initially called --> C with classes by stroustroup
// class --> extension of structures (in C)
// structures had limitations
//      - members are public
//      - No methods
// classes --> structures + more
// classes --> can have methods and properties
// classes --> can make few members as private & few as public
// structures in C++ are typedefed
// you can declare objects along with the class declarion like this:
/* class Employee{
            // Class definition
        } harry, rohan, lovish; */
// harry.salary = 8 makes no sense if salary is private

// Nesting of member functions


#include<iostream>
#include<string>
using namespace std;


class Binary
{
    string s;

    public :
        void read ( void ) ;
        void chc_bin ( void ) ;

        void ones ( void );
        void display ( void );
};

void Binary :: ones ( void )
{
    for( int i=0 ; i < s.size() ; i++){
        if ( s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }

}

void Binary  :: display (  ){
    cout << "displaying your binary number : "<< s << "\n" ;
}

void Binary :: read ()
{
    cout << "Enter a Binary Number : \n" ;
    cin >> s;

}

void Binary :: chc_bin(void)
{

    for (int i=0 ; i < s.length() ; i++ )
    {
        if ( s[i]!='0' && s[i]!='1' ){
            cout << "Incorrect Binary Format \n" ;
            exit(0) ;
        }
    }

    cout << "Correct Binary Format " << "\n";
}

int main()
{
    Binary b;

    b.read();

    b.chc_bin();

    b.ones();

    b.display();

    return 0;
}