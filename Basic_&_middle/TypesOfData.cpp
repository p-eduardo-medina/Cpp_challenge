#include <iostream>

using namespace std; //This commanf allows us to use cout and endl without the std:: prefix

// This program demonstrates different types of data in C++
int main() 
{
    char garde = 'A'; // Character
    string phrase = "Hello, World!"; // String
    int age = 25; // Integer
    float price = 19.99; // Floating point number
    double pi = 3.14159; // Double precision floating point number

    cout << "Grade: " << garde << endl;
    cout << "Phrase: " << phrase << endl;
    cout << "Age: " << age << endl;
    cout << "Price: " << price << endl;
    cout << "Pi: " << pi << endl;

    return 0;
}