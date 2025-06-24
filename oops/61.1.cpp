#include <iostream>
using namespace std;

int main() {
    try {
        cout << "Before exception" << endl;
        throw 42;  // Throwing an integer exception
        cout << "This line will not execute" << endl;
    } 
    catch (int e) {
        cout << "Caught exception: " << e << endl;
    }
    cout << "After catch block" << endl;
    return 0;
}
