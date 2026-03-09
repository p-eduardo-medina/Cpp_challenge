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
    int *p_num1{new int( 100 ) }; // dynamically allocated int initialized to 100 using direct initialization
    int *p_num2{new int{ 200 } }; // dynamically allocated int initialized to 200 using uniform initialization
    std::cout << "Dynamically allocated int: " << *dyn << "\n";
    std::cout << "Dynamically allocated int (direct initialization): " << *p_num1 << "\n";
    std::cout << "Dynamically allocated int (uniform initialization): " << *p_num2 << "\n";
    delete dyn;    // free memory
    delete p_num1;
    delete p_num2;

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

    //dangling pointer example
    int *danglingPtr {new int {17}}; // dynamically allocated int
    std::cout << "danglingPtr points to Before delete: " << danglingPtr << "\n";
    delete danglingPtr;
    std::cout << "danglingPtr points to After delete: " << danglingPtr << "\n";

    //Dynamic array allocation
    int size = 5;
    int *dynamicArray = new int[size]; // dynamically allocated array of integers
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = (i + 1) * 10; // initialize array elements
    }
    std::cout << "Dynamic array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << "\n";  

    int size_t {10};
    double *p_salaries { new double[size_t] }; // dynamically allocated array of doubles, will contain garbage values since it is not initialized
    int * p_student {new (std::nothrow) int [size_t]{}}; // dynamically allocated array of integers initialized to zero using nothrow and uniform initialization
    double *p_scores { new(std::nothrow) double[size_t]{1,2,3,4,5} }; // dynamically allocated array of doubles initialized to zero using nothrow and uniform initialization

    if(p_scores) { //nullptr check to ensure memory allocation was successful
        std::cout << "p_scores: "<< std::endl;
        for (int i = 0; i < size_t; ++i) {
            std::cout << "value: " << p_scores[i] << " & " << *(p_scores+i)<< std::endl; // print values in p_scores array
        };
    } else {
        std::cout << "Memory allocation for p_scores failed\n";
    }
    delete[] dynamicArray; // free memory allocated for dynamic array
    delete[] p_salaries; // free memory allocated for p_salaries array
    delete[] p_scores; // free memory allocated for p_scores array

    double *temperatures = new double[size_t] {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0}; // dynamically allocated array of doubles with 10 elements, initialized using nothrow and uniform initialization
    for(int i = 0; i < size_t; ++i) { // index-based for loop to print values in temperature array
        std::cout << "Temperature: " << temperatures[i] << " & " << *(temperatures+i) << std::endl;
    }
    delete[] temperatures; // free memory allocated for temperatures array

    //static array vs dynamic array
    int staticArray[5] = {1, 2, 3, 4, 5}; // static array of integers
    int *dynamicArray2 = new int[5] {1, 2, 3, 4, 5}; // dynamically allocated array of integers initialized using uniform initialization
    for( auto s: staticArray) { // range-based for loop to print values in static array
        std::cout << "Static array value: " << s << std::endl;
    }
    for(int i = 0; i < 5; ++i) { // index-based for loop to print values in dynamic array
        std::cout << "Dynamic array value: " << dynamicArray2[i] << " & " << *(dynamicArray2+i) << std::endl;
    }

    delete[] dynamicArray2; // free memory allocated for dynamic array

    // Pointer to pointer
    int **ptrToPtr = &ptrValue; // pointer to pointer, holds address of ptrValue
    std::cout << "ptrToPtr points to: " << ptrToPtr << "\n";
    std::cout << "ptrToPtr points to value: " << **ptrToPtr << "\n";    

    return 0;
}
