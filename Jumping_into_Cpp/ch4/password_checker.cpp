// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

// Try entering 5.99 and notice it's truncated to 5
// Try entering a letter, like 'a', and notice it's 0 


//
// No password checker is that simple
// For starters, it wouldn't be included in the source code.
//
int main()
{
    std::string password;

    std::cout << "Please enter your password: " << std::endl;

    getline(std::cin, password, '\n');

    if(password == "xyzzy")
    {
        std::cout << "Access Allowed" << std::endl;
    }
    else
    {
        std::cout << "Access Denied!" << std::endl;

        // Convenient way to stop program
        return 0;
    }
    //Continue onward!
}
