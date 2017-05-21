// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <string> 

int main()
{
    // Get line until the new line
    std::string user_name;
    std::cout << "Please enter your name: ";
    getline(std::cin, user_name, '\n');
    std::cout << "Hi " << user_name << std::endl;
    // Get line until the comma 
    std::string input_string_until_comma;
    std::cout << "Please enter comma separated input ";
    getline(std::cin, input_string_until_comma, ',');
    std::cout << "I got this: " << input_string_until_comma << std::endl;
}
