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
//
// Asks user if they want to quit
// OUT: true if user wants to quit
//
bool does_user_want_to_quit()
{
    bool choice = false;
    
    std::string user_input;

    std::cout <<"Wanna quit? [Y/N]\n";

    getline(std::cin, user_input , '\n');

    if(user_input == "Y")
    {
        choice = true;
    }

    return choice;
}

int main()
{
    bool user_wants_to_quit = false;

    int symbol_A = 0;

    int symbol_B = 0;

    int symbol_C = 0;

    srand( time(NULL) );

    std::cout <<"Hi! I'm a slot machine here to take your money \n"
              <<"You win if all numbers are 7's \n" 
              <<"Let's play! \n";
    //
    // srand returns a random number b/t 0 and a constant called RAND_MAX = 32767 at least
    //
    do
    {
        symbol_A = randRange(0,9);

        symbol_B = randRange(0,9);

        symbol_C = randRange(0,9);

        if(symbol_A == 7 && symbol_B == 7 && symbol_C == 7)
        {
            std::cout << symbol_A << " " 
                      << symbol_B << " "
                      << symbol_C << "\n"
                      << "You win! \n";
        }

        else
        {
            std::cout << symbol_A << " " 
                      << symbol_B << " "
                      << symbol_C << "\n"
                      << "You lose :( \n";
        }

        user_wants_to_quit = does_user_want_to_quit();
    }
    while(user_wants_to_quit != true);
}
