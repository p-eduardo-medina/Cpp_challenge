#include <iostream>

int main() {
    int value = 42;
    int &refValue = value; // refValue is a reference to value

    std::cout << "value: " << value << "\n";
    std::cout << "refValue: " << refValue << "\n";

    // Modifying refValue also modifies value
    refValue = 100;
    std::cout << "After modifying refValue:\n";
    std::cout << "value: " << value << "\n";
    std::cout << "refValue: " << refValue << "\n";

    // References must be initialized when declared
    // int &uninitializedRef; // This would cause a compilation error

    // References cannot be reseated to refer to another variable
    int anotherValue = 200;
    // refValue = anotherValue; // This does not change the reference, it assigns the value of anotherValue to value

    return 0;
}