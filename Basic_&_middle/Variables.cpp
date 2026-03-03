#include <iostream>

int main() 
{
    int myNum = 5;               // Integer (whole number)
    float myFloatNum = 5.99;     // Floating point number
    double myDoubleNum = 9.98;   // Floating point number (double precision)
    char myLetter = 'D';         // Character
    bool myBoolean = true;       // Boolean
    std::string myText = "Hello"; // String

    std::cout << "Integer: " << myNum << std::endl;
    std::cout << "Float: " << myFloatNum << std::endl;
    std::cout << "Double: " << myDoubleNum << std::endl;
    std::cout << "Character: " << myLetter << std::endl;
    std::cout << "Boolean: " << myBoolean << std::endl;
    std::cout << "String: " << myText << std::endl;

    return 0;
}