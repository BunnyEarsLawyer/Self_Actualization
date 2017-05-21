// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <string> 

int main()
{
    std::string user_name;
    std::cout << "Please enter your name: ";
    std::cin >> user_name;
    std::cout << "Hi " << user_name << std::endl;
}
