#include <iostream>
#include <cstring>

int main() {
    const char original_str [] {"The sky is Red"}; // array of characters initialized to a string literal
    const char* p_original_str {"The sky is Red"}; // pointer to the original string, initialized to point to the first character of original_str 
    std::cout << "Original string: " << original_str << "\n";
    std::cout << "Pointer to original string: " << p_original_str << "\n";

    std::cout << "strlen(original_str): " << std::strlen(original_str) << "\n"; // print the length of the original string using strlen
    std::cout << "sizeof(original_str): " << sizeof(original_str) << "\n"; // print the size of the original string using sizeof, which includes the null terminator

    std::cout << "strlen(original_str): " << std::strlen(p_original_str) << "\n"; // print the length of the original string using strlen on the pointer, which should give the same result as strlen(original_str)
    std::cout << "sizeof(p_original_str): " << sizeof(p_original_str) << "\n"; // print the size of the pointer, which is typically 8 bytes on a 64-bit system, and does not include the null terminator


    const char* str_data1{"Alabama"}; 
    const char* str_data2{"Blabama"}; 
    
    char str_data3[]{"Alabama"}; // string literal, stored in read-only memory, may be the same as str_data1 due to string literal pooling
    char str_data4[]{"Blabama"}; // string literal, stored in read-only memory, may be the same as str_data2 due to string literal pooling

    //Print out the comparation
    std::cout << "Comparing " << str_data1 << " and " << str_data2 << ": " << (std::strcmp(str_data1, str_data2) == 0 ? "Equal" : "Not Equal") << "\n"; // compare str_data1 and str_data2 using strcmp, which should return not equal
    std::cout << "Comparing "<< str_data1 << " and " << str_data3 << ": " << (std::strcmp(str_data1, str_data3) == 0 ? "Equal" : "Not Equal") << "\n"; // compare str_data1 and str_data3 using strcmp, which should return equal
    std::cout << "Comparing "<< str_data2 << " and " << str_data4 << ": " << (std::strcmp(str_data2, str_data4) == 0 ? "Equal" : "Not Equal") << "\n"; // compare str_data2 and str_data4 using strcmp, which should return equal  

    str_data1 = "Alabama"; 
    str_data2 = "Alabamb";

    //We use strchr to find all the characters one by one.
    const char* str{"Hey!! Try not. Do, or not. There is no try."};
    char target = 'T';
    const char* result = str; // pointer to the current position in the string, initialized to point to the first character of str
    int numIterations{}; // counter for the number of iterations

    while ( (result = std::strchr(result, target) ) != nullptr) 
        {
            std::cout << "Found '" << target << "' at position: " << result  << "\n"; // print the position of the found character, which is the pointer to the character in the string
            result++; // move the pointer to the next character after the found character to continue searching for the next occurrence
            numIterations++; // increment the counter for each iteration
        }
    std::cout << "Total iterations: " << numIterations << "\n";
    
    char input[] {"C:/Users/Eduardo Medina/Documents/Programming/Cpp/Advanced C++/C-String Manipulation/input.txt"}; // array of characters initialized to a file path string literal
    char* output = std::strrchr(input, '/'); // pointer to the last occurrence of '/' in the input string, which should point to the last '/' in the file path
    if (output) { // check if the pointer is not null, which means that '/' was found in the string
        std::cout << output + 1 << "\n"; // print the substring after the last '/', which should be the file name "input.txt"
    }
    
    //C-STRING cCONCATENAATION & COPY
    char str1[20] {"Hello, "}; // array of characters initialized to "Hello, ", with enough space for concatenation
    char str2[] {"World!"}; // array of characters initialized to "World!"
    std::strcat(str1, str2); // concatenate str2 to str1, which modifies str1 to contain "Hello, World!"
    std::cout << "Concatenated string: " << str1 << "\n";
    
    return 0;

}