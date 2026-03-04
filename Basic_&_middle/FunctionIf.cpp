#include <iostream>

using namespace std;

int getMaxNumber(int num1, int num2, int num3) 
{
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }
}
int main() 
{
    bool isMale = true;
    bool isTall = false;
    
    if (isMale && isTall) { //  || is or, && and ! not,  are logical operators
        cout << "You are a tall male." << endl;
    } else if (isMale && !isTall) {
        cout << "You are a short male." << endl;
    } else if (!isMale && isTall) {
        cout << "You are a tall female." << endl;
    } else {
        cout << "You are a short female." << endl;
    }

    return 0;
}