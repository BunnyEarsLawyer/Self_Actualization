// How to build: $clang++ -std=c++11 name_of_program.cpp
// How to build: $gcc -std=c++11 name_of_program.cpp
// How to build: $g++ name_of_program.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <cstdlib>
#include <ctime>

enum HowClose 
{
    HOT = 100,
    COLD = 0,
    CORRECT = 1
};

//
// This program solves the 'Guess what number I'm thinking' problem
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
// Reports if the guess is close, far, or exact
// IN = the number guessed and the correct number to compare to
// OUT = a enumarated number that indicates if we are close or correct
//
int report_how_close(int guess, int correct_number)
{

    int hot_or_cold = 0;

    if( guess == correct_number )
    {

        std::cout <<"Wow! You got it\n"
                  << guess << " is correct\n";

        hot_or_cold = CORRECT;
        
    }
    else if ( abs(guess - correct_number) < 10 )
    {

        std::cout << guess << " is hot\n";

        hot_or_cold = HOT;

    }
    else
    {

        std::cout << guess << " is cold\n";

        hot_or_cold = COLD;

    }

    return hot_or_cold;
}

//
// Program thinks of a number b/t 1 and 100
// the same program will try to guess what it is
// based on the feedback given
// 
int main()
{
    std::cout <<"Hi! I'm thinking of a number between 1 and 100 \n"
              <<"Can someone guess what it is?\n"  ;

    int robot_guess = 0;

    int the_correct_number = 0;

    int is_correct = 2;

    int range_low = 0;
    
    int range_high = 100;

    srand( time(NULL) );

    the_correct_number = randRange(range_low,range_high);

    while(is_correct != CORRECT)
    {
        is_correct = report_how_close(robot_guess, the_correct_number);

        if( is_correct == HOT)
        {
            ++robot_guess;
        }
        else if( is_correct == COLD)
        {
            robot_guess = randRange(0,100);
        } 
    }
}




























