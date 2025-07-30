#include <iostream>
using namespace std;

int main() {
    // Declare and initialize variables
    int a = 10; // Integer variable
    double b = 20.5; // Double variable
    char ch = 'A'; // Character variable
    bool isTrue = true; // Boolean variable

    // Output the values of the variables
    cout << "Integer: " << a << endl;
    cout << "Double: " << b << endl;
    cout << "Character: " << ch << endl;
    cout << "Boolean: " << (isTrue ? "True" : "False") << endl;

    // Example of type conversion
  	float f = 36.5;
    int n = 3;
    char  c = 'C';

    cout << (int)c << endl;

    int sum = n + c;
    cout << sum;




  	cout << f;
  
    return 0;
}