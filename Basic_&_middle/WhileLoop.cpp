#include <iostream>

using namespace std;
int main() 
{
    int index = 1;
    while (index <= 5) {
        cout << index << endl; // Print the current value of index
        index++; // Increment index by 1
    }

    do
    {
        cout << index << endl; // Print the current value of index
        index++; // Increment index by 1
    } while (index <= 5); // Check the condition after executing the loop body

    return 0;
    
}