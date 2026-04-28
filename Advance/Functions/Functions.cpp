#include <iostream>
#include "max_function.h"

//Function Declarations
int max(int a, int b);
int min(int a, int b);

void say_age(int* age);
void say_age_ref(int& age);

int main(int argc, char const *argv[])
{
    int a{2};
    int b{3};
    std::cout << "The maximum of " << a << " and " << b << " is: " << max(a, b) << "\n\t\t\t" <<std::endl;
    std::cout << "The minimum of " << a << " and " << b << " is: " << min(a, b) << "\n\t\t\t" <<std::endl;

    int max_val = max(234, 765);
    int min_val = min(234, 765);

    std::cout << "The maximum of 234 and 765 is: " << max_val << "\n\t\t\t" <<std::endl;
    std::cout << "The minimum of 234 and 765 is: " << min_val << "\n\t\t\t" <<std::endl;

    //Functions Across Multiple Files - Compilation Model Revisited
    int new_max_val = newMax(10, 20);
    int new_min_val = newMin(10, 20);
    std::cout << "The maximum of 10 and 20 is: " << new_max_val << "\n\t\t\t" <<std::endl;
    std::cout << "The minimum of 10 and 20 is: " << new_min_val << "\n\t\t\t" <<std::endl;

    std::cout << "The result of incr_mult(2, 3) is: " << incr_mult(4, 6) << "\n\t\t\t" <<std::endl;

    //Passing by Reference using Pointers
    int age{25};
    say_age(&age);

    //Passing by Reference using References
    int age_ref{15};
    say_age_ref(age_ref);
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

void say_age(int* age){
    std::cout << "Your age (+1) is: " << ++(*age) << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
    std::cout << "Your age (+1) is: " << ++(*age) << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
    std::cout << "Your age (+1) is: " << ++(*age) << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
    ++(*age);
    std::cout << "Your age (+1) is: " << *age << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
}

void say_age_ref(int& age){
    std::cout << "Your age (+1) is: " << ++age << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
    std::cout << "Your age (+1) is: " << ++age << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
    std::cout << "Your age (+1) is: " << ++age << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
    ++age;
    std::cout << "Your age (+1) is: " << age << " at memory address: " << &age << "\n\t\t\t" <<std::endl;
}