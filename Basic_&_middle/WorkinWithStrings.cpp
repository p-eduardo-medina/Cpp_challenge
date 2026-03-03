#include <iostream>

using namespace std;

int main() 
{
    string name = "Eduardo";
    string greeting = "Hello, World! \n\tWelcome to C++ programming.";
    cout << greeting << endl;

    cout << "\n\n\n" <<endl; // This will print 3 new lines 

    cout << name << endl;
    cout << name[0] << endl;
    cout << name.find("ardo", 0) << endl; // This will return the index of the first occurrence
                                        // of "ardo" and the index wher to start searching (0 means start from the beginning of the string) 
    cout << name.substr(2, 4) << endl; // This will return a substring starting from index 2 and WITH A LENGTH of 4 characters
    cout << name.substr(2, name.length()) << endl; // This will return a substring starting from index 2 to the end of the string
    cout << name.length() << endl;

    return 0;
}