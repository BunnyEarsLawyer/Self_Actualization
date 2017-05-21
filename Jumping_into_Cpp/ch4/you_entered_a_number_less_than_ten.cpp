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
    int number_from_user;
    std::cout << "Please enter a number" << std::endl;
    std::cin >> number_from_user;
    std::cout << "You entered: " << number_from_user << " I will keep quiet if it's larger than or equal to ten :)" << std::endl;
    if(number_from_user < 10)
    {
        std::cout << "You entered a number that is less than 10" << std::endl;
    }
}
