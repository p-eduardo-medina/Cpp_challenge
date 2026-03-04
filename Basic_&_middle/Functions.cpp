#include <iostream>

using namespace std;

void sayHI() 
{
    cout << "Hello User!" << endl;
}

string sayHII(string name, int age) 
{
    return "Hello, " + name + "! You are " + to_string(age) + " years old.";
}

int main() 
{
    cout << "TOP" << endl;
    sayHI();
    cout << "BOTTOM" << endl;
    cout << "The message is: " << sayHII("Alice", 25) << endl;
    return 0;
}