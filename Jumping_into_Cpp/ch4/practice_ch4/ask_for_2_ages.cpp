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
    int user_a_age;
    int user_b_age;

    std::cout << "Please enter your age user A" << std::endl;
    std::cin >> user_a_age;
    std::cout << "Please enter your age user B" << std::endl;
    std::cin >> user_b_age;

    if(user_a_age > 100 && user_b_age > 100)
    {
        std::cout << "Both of you are ripe" << std::endl;
    }
    else
    {
        std::cout << "You are barely out of the womb" << std::endl;
    }
}
