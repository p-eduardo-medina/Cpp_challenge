#include <iostream>

//Function Declarations
int max(int a, int b);
int min(int a, int b);

int main(int argc, char const *argv[])
{
    int a{2};
    int b{3};
    std::cout << "The maximum of " << a << " and " << b << " is: " << max(a, b) << "\n\t\t\t:D" <<std::endl;
    std::cout << "The minimum of " << a << " and " << b << " is: " << min(a, b) << "\n\t\t\t:D" <<std::endl;
    
    
    return 0;   
}

//Function Definitions
int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b){
    if (a < b)
        return a;
    else
        return b;
}
