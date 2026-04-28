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

    return 0;

}