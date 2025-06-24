#include<iostream>
using namespace std;

class Shop{
    int itemId[100];
    int itemPrice[100];
    int counter;

    public : 
        void initCounter(void){counter =0 ;}
        void setPrice(void);
        void displayPrice(void);
};

void Shop :: setPrice(void){
    cout<<"Enter Id of your Item "<<counter+1<<"\n";
    cin>>itemId[counter];
    cout<<"Enter Price of your item \n";
    cin>>itemPrice[counter];

    counter++;
}

void Shop :: displayPrice(void){
    for(int i=0;i<counter;i++){
        cout<<"The price of item with id "<<itemId[i]<<" is "<<itemPrice[i]<<"\n";
    }
}

int main(){

    Shop dukaan;

    dukaan.initCounter();

    // cout<<dukaan.counter<<"\n";
    //since counter is not in any private or public or protected so by default it is in private

    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();

    dukaan.displayPrice();

    return 0;
}

/*
devanshu@devanshu:~/Desktop/cp/cp/oop$ ./a
Enter Id of your Item 1
1001   
Enter Price of your item 
12
Enter Id of your Item 2
1002 
Enter Price of your item 
23
Enter Id of your Item 3
1003
Enter Price of your item 
34
The price of item with id 1001 is 12
The price of item with id 1002 is 23
The price of item with id 1003 is 34
*/