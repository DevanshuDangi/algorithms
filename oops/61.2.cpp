//multiple catch blocks

#include <iostream>
using namespace std;

int main() {
    try {
        throw 3.14;  // Throwing a double
    } 
    catch (int e) {
        cout << "Caught an integer: " << e << endl;
    }
    catch (double e) {
        cout << "Caught a double: " << e << endl;
    }
    catch (...) { // Catch-all block
        cout << "Caught an unknown exception" << endl;
    }
    return 0;
}

// The exception 3.14 is of type double, so it is caught in catch(double e).
// If no matching catch block is found, the program will terminate.
// The catch (...) block is a generic catch-all handler that catches any type of exception.