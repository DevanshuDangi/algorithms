// Standard Exception Handling (Using std::exception)

#include <iostream>
#include <stdexcept>  // Contains standard exception classes

using namespace std;

int main() {
    try {
        throw runtime_error("Something went wrong!");
    } 
    catch (exception& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }
    return 0;
}
