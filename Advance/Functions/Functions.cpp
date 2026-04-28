#include <iostream>
#include "max_function.h"

//Function Declarations
int max(int a, int b);
int min(int a, int b);



int main(int argc, char const *argv[])
{
    int a{2};
    int b{3};
    std::cout << "The maximum of " << a << " and " << b << " is: " << max(a, b) << "\n\t\t\t:D" <<std::endl;
    std::cout << "The minimum of " << a << " and " << b << " is: " << min(a, b) << "\n\t\t\t:D" <<std::endl;

    int max_val = max(234, 765);
    int min_val = min(234, 765);

    std::cout << "The maximum of 234 and 765 is: " << max_val << "\n\t\t\t:D" <<std::endl;
    std::cout << "The minimum of 234 and 765 is: " << min_val << "\n\t\t\t:D" <<std::endl;

    //Functions Across Multiple Files - Compilation Model Revisited
    int new_max_val = newMax(10, 20);
    int new_min_val = newMin(10, 20);
    std::cout << "The maximum of 10 and 20 is: " << new_max_val << "\n\t\t\t:D" <<std::endl;
    std::cout << "The minimum of 10 and 20 is: " << new_min_val << "\n\t\t\t:D" <<std::endl;

    std::cout << "The result of incr_mult(2, 3) is: " << incr_mult(4, 6) << "\n\t\t\t:D" <<std::endl;

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

