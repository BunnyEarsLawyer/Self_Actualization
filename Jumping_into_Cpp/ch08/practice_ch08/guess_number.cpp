// How to build: $clang++ -std=c++11 name_of_program.cpp
// How to build: $gcc -std=c++11 name_of_program.cpp
// How to build: $g++ name_of_program.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <cstdlib>
#include <ctime>
//
// Modulus (%) returns the remainder e.g. 4/3 remainder is 1.
// If you divide a number by 4, remainder is b/c 0 and 3.
// If you divide your random number by the size of your range, you end up with a number 
// b/t 0 and the size of the range minus 1.
//
int randRange(int low, int high)
{
    //
    // We get a randome number, get it to be b/t 0 and the number of values in our range
    // E.g. 0 to 10 has 11 values.
    // E.g. 4 to 10 has 7 values.
    // then add the lowest possible value
    //
    return rand() % (high - low + 1) + low;
}

int main()
{
    int user_guess = 0;

    int the_correct_number = 0;

    srand( time(NULL) );

    the_correct_number = randRange(0,100);

    std::cout <<"Hi! I'm thinking of a number between 1 and 100 \n"
              <<"Can you guess what it is?\n"  ;

    std::cin >> user_guess;

    //
    // Check if it's close, far, or exact
    //
    if( user_guess == the_correct_number )
    {
        std::cout <<"Wow! You got it\n";
        std::cout << user_guess << " is correct\n";
        
    }
    else if ( abs(user_guess - the_correct_number) < 10 )
    {
        std::cout << "It's close\n";
    }
    else
    {
        std::cout << "It's far\n";
    }

}




























