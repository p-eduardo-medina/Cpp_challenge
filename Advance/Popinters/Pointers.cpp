#include <iostream>
#include <memory>

int main() {
    // Basic pointer usage
    int value = 42;
    int *ptrValue = &value;                  // pointer holds address of value

    std::cout << "value: " << value << "\n";
    std::cout << "ptrValue points to: " << *ptrValue << "\n";
    std::cout << "address stored in ptrValue: " << ptrValue << "\n";

    // Null pointer
    int *nullPtr = nullptr;
    if (nullPtr == nullptr) {
        std::cout << "nullPtr is null\n";
    }

    // Pointer arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;   // points to first element
    for (int i = 0; i < 5; ++i) {
        std::cout << "arr[" << i << "] = " << *(p + i) << "\n";
    }

    // Dynamic allocation
    int *dyn = new int(100);
    std::cout << "Dynamically allocated int: " << *dyn << "\n";
    delete dyn;    // free memory

    // Unique pointer (smart pointer)
    std::unique_ptr<int> uptr = std::make_unique<int>(55);
    std::cout << "unique_ptr holds: " << *uptr << "\n";

    // Pointer to function
    auto func = [] (int x) { // lambda function that doubles the input
        return x * 2; 
    };
    int (*funcPtr)(int) = func; // function pointer assigned to the lambda function
    
    auto isGreaterThan100 = [] (int x) { // lambda function that checks if input is greater than 100
        return x > 100; 
    };
    bool (*isGreaterThan100Ptr)(int) = isGreaterThan100; // function pointer assigned to the lambda function
    std::cout << "function pointer result: " << funcPtr(5) << "\n";

    int *p_number {}; // pointer initialized to null. Can only store an address of a variable of type int.
    double *p_fractional_number {}; // pointer initialized to null. Can only store an address of a variable of type double.

    int int_var {10};
    int *p_int_var {&int_var}; // pointer initialized to the address of int_var
    std::cout << "int_var: " << int_var << "\n";
    std::cout << "p_int_var: " << p_int_var << "\n";
    std::cout << "p_int_var points to: " << *p_int_var << "\n";

    char * p_message {"Hello, World!"}; // pointer initialized to a string literal
    std::cout << "p_message: " << p_message << "\n"; // string literals are stored in read-only memory, 
                                                    //so we should not modify the contents of p_message
    std::cout << "The value stored at p_message is: " << *p_message << "\n";// dereferencing p_message gives us the first character of the string literal
    
    char message[] {"Hello, World!"}; // array of characters initialized to a string literal
    std::cout << "message: " << message << "\n"; // arrays of characters are stored in modifiable memory, so we can modify the contents of message
    message[0] = 'h'; // This is valid since message is an array, not a pointer to a string literal
    std::cout << "After modifying message: " << message << "\n";

    return 0;
}
