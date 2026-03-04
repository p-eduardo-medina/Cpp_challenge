#include <iostream>

using namespace std;

int main() 
{
    int age;
    string name;
    cout << "Please enter your age: ";
    cin >> age;

    cout << "You entered: " << age << ", So this is your age" << endl;
    cout << "Please enter your name: ";
    getline(cin, name); // To read the name with spaces
    cout << "You entered: " << name << ", So this is your name" << endl;
    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
}