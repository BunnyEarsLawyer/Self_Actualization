// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>
//
// Will ask until infinity for your password
// Until you get it right
//
int main()
{
    int n_beer_bottles = 1;

    while (n_beer_bottles < 100 ) // Condition
    {
        std::cout << n_beer_bottles << " bottles of beer \n";
        std::cout << n_beer_bottles << " bottles of beer \n";
        std::cout << "Take one out! Pass it around! \n";
        std::cout << n_beer_bottles << " bottles of beer \n";
        n_beer_bottles++;
    }

}
