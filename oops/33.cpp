//dynamic initialisation of objects using constructors

#include<iostream>
using namespace std;

class BankDeposit
{
    int principalval;
    int years;
    float rate;

    float returnvalue;

    public : 
        BankDeposit(){}

        BankDeposit(int pv,int y,float r)// if rate is in float datatype
        {
            principalval=pv;
            years=y;
            rate =r;
            float interestrate=r;

            returnvalue=principalval;

            for(int i=0;i<y;i++)
            {
                returnvalue*=(1+interestrate);
            }

        }

        BankDeposit(int pv,int y,int r)// if rate is in int datatype
        {
            principalval=pv;
            years=y;
            rate =r;
            float interestrate=float(r)/100;

            returnvalue=principalval;

            for(int i=0;i<y;i++)
            {
                returnvalue*=(1+interestrate);
            }

        }

        void show(){
            cout<<endl<<"Principal amount was "<<
            principalval<< ". Return value after "<<years
            << " years is "<<returnvalue<<endl;
        }
};

int main()
{
    BankDeposit bd1,bd2,bd3;

    int p, y;
    float r;
    int R;
    
    
    cout<<"Enter the value of p y and r"<<endl;
    cin>>p>>y>>r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();

    cout<<"Enter the value of p y and R"<<endl;
    cin>>p>>y>>R;
    bd2 = BankDeposit(p, y, R);
    bd2.show();

    return 0;
}

/*
Enter the value of p y and r
1000 5 0.16

Principal amount was 1000. Return value after 5 years is 2100.34
Enter the value of p y and R
1000 5 16

Principal amount was 1000. Return value after 5 years is 2100.34
*/