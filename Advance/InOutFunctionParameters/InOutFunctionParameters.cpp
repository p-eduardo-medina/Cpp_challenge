#include <iostream>
void max_str(const std::string& input1, const std::string& input2, 
                    std::string& output) {
    if (input1.length() > input2.length()) {
        output = input1;
    } else {
        output = input2;
    }
}

void max_int(int input1, int input2, int& output) {
    if (input1 > input2) {
        output = input1;
    } else {
        output = input2;
    }
}
void max_double(double input1, double input2, double* output){
    if (input1 > input2){
        *output = input1;
    }else{
        *output = input2;
    }

//Overloading functions
}
int max(int a, int b){
    std::cout << "int overload called!" << std::endl;
    return (a > b) ? a : b; // Ternary operator, returns a if a is greater than b, otherwise returns b
}
double max(double a, double b){
    std::cout << "double overload called!" << std::endl;
    return (a > b) ? a : b;
}
double max(double a, int b){
    std::cout << "double and int overload called!" << std::endl;
    return (a > b) ? a : b;
}


int main() {
    
    std::string output;
    std::string input1 = "Hello World";
    std::string input2 = "World!!!";
    max_str(input1, input2, output);
    std::cout << "The longer string is: " << output << "\n\n" << std::endl;

    int out_int;
    int in1{100};
    int in2{20};
    max_int(in1, in2, out_int);
    std::cout << "The larger integer is: " << out_int << "\n\n" << std::endl;

    double out_double;
    double in_double1{3.14};
    double in_double2{20.71};
    max_double(in_double1, in_double2, &out_double);
    std::cout << "The larger double is: " << out_double << "\n\n" << std::endl;

    int x{4};
    int y{5};
    double a{4.5};
    double b{7.951};

    auto result = max(x, y); // Calls the int overload
    std::cout << "The larger integer is: " << result << "\n\n" << std::endl;

    auto result2 = max(a, b); // Calls the double overload
    std::cout << "The larger double is: " << result2 << "\n\n" << std::endl;    

    auto result3 = max(a, 120); // Calls the double and int overload
    std::cout << "The larger value is: " << result3 << "\n\n" << std::endl;

    return 0;

}