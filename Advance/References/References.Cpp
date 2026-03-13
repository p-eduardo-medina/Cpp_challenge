#include <iostream>

int main() {
    //int value = 42;
    int value {42}; // value is an integer variable initialized to 42 using uniform initialization
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

    char original_str [] {"Hello, World!"}; // array of characters initialized to a string literal
    char dest_str[std::size(original_str)]; // initiate a destination array of the same size as the original string

    // Turn this to uppercase. Change the array
    for(size_t i = 0; i < std::size(original_str); ++i) { // loop through each character in the original string
        dest_str[i] = std::toupper(original_str[i]);
    }
    std::cout << "Original string: " << original_str << "\n";
    std::cout << "Destination string: " << dest_str << "\n";

    //Now to lowercase. Change the array
    for(size_t i = 0; i < std::size(dest_str); ++i) { // loop through each character in the destination string
        dest_str[i] = std::tolower(dest_str[i]);
    }
    std::cout << "Destination string (lowercase): " << dest_str << "\n";

    return 0;
}