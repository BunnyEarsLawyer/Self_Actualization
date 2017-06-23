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
    	case 1:
      	    card_name = " One ";
      	    break;
    	case 2:
      	    card_name = " Two ";
      	    break;
    	case 3:
      	    card_name = " Three ";
      	    break;
    	case 4:
      	    card_name = " Four ";
      	    break;
    	case 5:
      	    card_name = " Five ";
      	    break;
    	case 6:
      	    card_name = " Six ";
      	    break;
    	case 7:
      	    card_name = " Seven ";
      	    break;
    	case 8:
      	    card_name = " Eight ";
      	    break;
    	case 9:
      	    card_name = " Nine ";
      	    break;
    	case 10:
      	    card_name = " Ten ";
      	    break;
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

std::string lookup_suit(int number)
{
    std::string suit_name;

    switch(number)
    {
        case 1:
            suit_name = "HEARTS";
            break;
        case 2:
            suit_name = "SPADES";
            break;
        case 3:
            suit_name = "CLUBS";
            break;
        case 4:
            suit_name = "DIAMONDS";
            break;

        default:
            std::cout << "Error: I don't know how to write this input \n" << std::endl;
            break;
    }

    return suit_name;
}


int main()
{
    bool user_wants_to_quit = false;

    //
    // In poker, Ace (14) > King (13) > Queen (12) > Jack (11), 10,..., 2
    //
    int card_value_1 = 1;
    int card_value_2 = 1;
    int card_value_3 = 1;
    int card_value_4 = 1;
    int card_value_5 = 1;
    // Each suit has 13 cards:`
    // Clubs
    // Diamonds
    // Hearts
    // Spades   
    int card_symbol_1 = 1;
    int card_symbol_2 = 1;
    int card_symbol_3 = 1;
    int card_symbol_4 = 1;
    int card_symbol_5 = 1;

    srand( time(NULL) );

    std::cout <<"Hi! Let's play poker.\n"
              <<"Here are your cards. Mine are hidden. \n";
    //
    // srand returns a random number b/t 0 and a constant called RAND_MAX = 32767 at least
    //
    do
    {

        card_value_1 = randRange(1,14);
        card_value_2 = randRange(1,14);
        card_value_3 = randRange(1,14);
        card_value_4 = randRange(1,14);
        card_value_5 = randRange(1,14);

        card_symbol_1 = randRange(1,4);
        card_symbol_2 = randRange(1,4);
        card_symbol_4 = randRange(1,4);
        card_symbol_4 = randRange(1,4);
        card_symbol_5 = randRange(1,4);

        std::cout << lookup_card_name(card_value_1) 
                  << card_value_1 
                  << " of " 
                  << card_symbol_1 
                  << lookup_suit(card_symbol_1) 
                  << std::endl;

        std::cout << lookup_card_name(card_value_2) 
                  << card_value_2 
                  << " of " 
                  << card_symbol_2 
                  << lookup_suit(card_symbol_2) 
                  << std::endl;

        std::cout << lookup_card_name(card_value_3) 
                  << card_value_3 
                  << " of " 
                  << card_symbol_3 
                  << lookup_suit(card_symbol_3) 
                  << std::endl;

        std::cout << lookup_card_name(card_value_4) 
                  << card_value_4 
                  << " of " 
                  << card_symbol_4 
                  << lookup_suit(card_symbol_4) 
                  << std::endl;

        std::cout << lookup_card_name(card_value_5) 
                  << card_value_5 
                  << " of " 
                  << card_symbol_5 
                  << lookup_suit(card_symbol_5) 
                  << std::endl;

	//
	// Are the five cards any type of winners?
	//

//	is_winner = is_royal_flush();


        user_wants_to_quit = does_user_want_to_quit();
    }
    while(user_wants_to_quit != true);
}
