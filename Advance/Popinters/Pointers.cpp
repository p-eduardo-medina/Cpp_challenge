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
    int arr[5] = {1, 2, 3, 4, 5};
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
    auto func = [] (int x) { return x * 2; };
    int (*funcPtr)(int) = func;
    std::cout << "function pointer result: " << funcPtr(5) << "\n";

    return 0;
}
