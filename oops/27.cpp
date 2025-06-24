//Friend classes and member friend functoins

#include<iostream>
using namespace std;

//forward declaration  : otherwise line 15 will give error thinking what is Complex as it is not assigned before SumRealComplex function
class Complex;

class Calculator
{
    public : 
        int add(int a,int b)
        {
            return a+b;
        }

        int sumRealComplex(Complex ,Complex );
        int sumComplexComplex(Complex ,Complex );

};

class Complex
{
    int a,b;

    // friend int Calculator :: sumRealComplex(Complex o1,Complex o2);  
    // // it means calculator ke sumRealComplex ko permision di jati h Complex ke private parts ko access krne ki

    // friend int Calculator :: sumComplexComplex(Complex o1,Complex o2);  
    // // it means calculator ke sumComplexComplex ko permision di jati h Complex ke private parts ko access krne ki


    // friend int Calculator :: sumRealComplex(Complex o1,Complex o2);  
    // friend int Calculator :: sumComplexComplex(Complex o1,Complex o2);  
    // //suppose aise aur 100 function ho gye toh ham sabko bar bar permission thodi denge so we can add the class Calculator as friend

    

    //individually declaring fundtions as friends
    // friend int Calculator :: sumRealComplex(Complex o1,Complex o2);  
    // friend int Calculator :: sumComplexComplex(Complex o1,Complex o2);

    //making class as friend so class ke andar sabko permsion h Complex ke private parts ko access krne ki
    //declaring the entire calculator as friend
    friend class Calculator;


    public:
        void setNumber(int v1,int v2)
        {
            a=v1;
            b=v2;
        }

        void printNumber()
        {
            cout<<"Your number is "<<a<<" + "<<b<<"i\n";
        }
};

//we are writiung this function after Complex class because here we are using a and b which is defined in Complex
int Calculator :: sumRealComplex(Complex o1,Complex o2)
{
    return (o1.a+o2.a) ;
}

int Calculator :: sumComplexComplex(Complex o1,Complex o2)
{
    return (o1.b+o2.b) ;
}

int main()
{
    Complex o1,o2;
    o1.setNumber(1,5);
    o1.printNumber();
    o2.setNumber(2,99);
    o2.printNumber();

    Calculator calc;
    
    int res=calc.sumRealComplex(o1,o2);
    cout<<"The sum of the real part of o1 an  o2 is : "<<res<<"\n";

    int resc=calc.sumComplexComplex(o1,o2);
    cout<<"The sum of the complex part of o1 an  o2 is : "<<resc<<"\n";


    return 0;
}