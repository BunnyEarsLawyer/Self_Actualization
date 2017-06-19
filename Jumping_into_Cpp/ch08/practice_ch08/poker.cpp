// How to build: $clang++ -std=c++11 name_of_program.cpp
// How to build: $gcc -std=c++11 name_of_program.cpp
// How to build: $g++ name_of_program.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <cstdlib>
#include <ctime>
//
// Play poker
// Provide 5 cards to the player, let player choose new cards
// Round of betting
// Each player may discard up to 3 cards.
// Player with best hand wins. 
// 
int randRange(int low, int high)
{
    //
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

std::string lookup_card_name(int card_value)
{

    std::string card_name;

    switch ( card_value )
    {
    	case 11:
      	    card_name = " Jack ";
      	    break;
    	case 12:
      	    card_name = " Queen ";
    	    break;
    	case 13:
      	    card_name = " Queen ";
    	    break;
    	case 14:
      	    card_name = " Ace ";
    	    break;

	default:
      	    std::cout << "Error: Bad input. Quitting\n" << std::endl;
      	    break;
    }

    return card_name;

}
int main()
{
    bool user_wants_to_quit = false;

    //
    // In poker, Ace (14) > King (13) > Queen (12) > Jack (11), 10,..., 2
    //
    int card_value_1 = 0;
    int card_value_2 = 0;
    int card_value_3 = 0;
    int card_value_4 = 0;
    int card_value_5 = 0;
    // Each suit has 13 cards:`
    // Clubs
    // Diamonds
    // Hearts
    // Spades   
    int card_symbol_1 = 0;
    int card_symbol_2 = 0;
    int card_symbol_3 = 0;
    int card_symbol_4 = 0;
    int card_symbol_5 = 0;

    srand( time(NULL) );

    std::cout <<"Hi! Let's play poker.\n"
              <<"Here are your cards. Mine are hidden. \n";
    //
    // srand returns a random number b/t 0 and a constant called RAND_MAX = 32767 at least
    //
    do
    {
        card_value_1 = randRange(0,14);
        card_value_2 = randRange(0,14);
        card_value_3 = randRange(0,14);
        card_value_4 = randRange(0,14);
        card_value_5 = randRange(0,14);

        card_symbol_1 = randRange(0,4);
        card_symbol_2 = randRange(0,4);
        card_symbol_3 = randRange(0,4);
        card_symbol_4 = randRange(0,4);
        card_symbol_5 = randRange(0,4);

        std::cout << card_value_1 << " of " << card_symbol_1 << std::endl;
        std::cout << card_value_2 << " of " << card_symbol_2 << std::endl;
        std::cout << card_value_3 << " of " << card_symbol_3 << std::endl;
        std::cout << card_value_4 << " of " << card_symbol_4 << std::endl;
        std::cout << card_value_5 << " of " << card_symbol_5 << std::endl;

        user_wants_to_quit = does_user_want_to_quit();
    }
    while(user_wants_to_quit != true);
}
