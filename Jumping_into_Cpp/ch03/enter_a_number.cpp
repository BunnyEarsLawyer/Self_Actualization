// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

// Try entering 5.99 and notice it's truncated to 5
// Try entering a letter, like 'a', and notice it's 0 

int main()
{
    int this_is_a_number;
    std::cout << "Please enter a number" << std::endl;
    std::cin >> this_is_a_number;
    std::cout << "You entered: " << this_is_a_number << std::endl;
}
