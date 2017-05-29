// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>
//
// Will keep adding numbers and printing result 
// Until user enters a zero 
//
int main()
{
    int running_sum    = 0;
    int current_number = 0;

    while (1)
    {
        std::cout << "Please enter a number to add to the running sum: " << std::endl;

        std::cin >> current_number;

        if( current_number == 0)
        {

            std::cout << "User entered a 0. Stopping with running sum at " << running_sum << std::endl;

            break;

        }

        running_sum += current_number;
    }
    
}
