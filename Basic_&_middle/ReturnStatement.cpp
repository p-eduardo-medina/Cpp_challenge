#include <iostream>

using namespace std;

double cube(double num) 
{
    return num * num * num; // Return the cube of the number
}

int main() 
{
    double number = 3.0, result = cube(number); // Call the cube function and store the result
    cout << "The cube of " << number << " is: " << result << endl; // Print the stored result
    return 0;
}