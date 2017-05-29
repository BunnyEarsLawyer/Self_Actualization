// How to build: $clang++ -std=c++11 name_of_program.cpp
// How to build: $gcc -std=c++11 name_of_program.cpp
// How to build: $g++ name_of_program.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    //
    // Seed in the time
    // srand returns a random number b/t 0 and a constant called RAND_MAX = 32767 at least
    //
    int my_random_number = 0;
    srand( time(NULL) );
    my_random_number = rand();
    std::cout << "Random number from srand: " << my_random_number << std::endl;
}
