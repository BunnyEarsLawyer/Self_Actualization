// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>
/*
You should be using single quotes for characters. Double quotes means you're using a (potentially single-character) string literal, which is represented as a const char * (pointer to constant character).
*/

//
// Global variables
//

//
// Board 3x3
//
char board[3][3];

enum SquareState
{
    TTT_X     = 1,
    TTT_O     = 2,
    TTT_BLANK = 3

};

//
// Functions are called as needed 
//

//
// There are 12 possible 3 in a row scnearios, only need to check 8
//
bool check_cross() 
{

   // Do not assign a value to this bool. Otherwise it's not updated.
   bool is_winner;

   // I have no choice, I can't check all 3 at the same time
   if(  board[1][1]  == board[0][0] && board[1][1]  == board[2][2]  )
   {

        is_winner = true;

   }
   if(  board[1][1]  == board[0][2] && board[1][1]  == board[2][0]  )
   {

        is_winner = true;

   }

   return is_winner;
}

bool check_horizontal_lines() 
{

   bool is_winner;

   // I have no choice, I can't check all 3 at the same time
   if(  board[0][0]  == board[0][1] && board[0][0]  == board[0][2]  )
   {

        is_winner = true;

   }
   if(  board[1][0]  == board[1][1] && board[1][0]  == board[1][2]  )
   {

        is_winner = true;

   }
   if(  board[2][0]  == board[2][1] && board[2][0]  == board[2][2]  )
   {

        is_winner = true;

   }
   
   return is_winner;
}

bool check_vertical_lines() 
{

   bool is_winner;

   // I have no choice, I can't check all 3 at the same time
   if(  board[0][0]  == board[1][0] && board[0][0]  == board[2][0]  )
   {

        is_winner = true;

   }
   if(  board[0][1]  == board[1][1] && board[0][1]  == board[2][1]  )
   {

        is_winner = true;

   }
   if(  board[0][2]  == board[1][2] && board[0][2]  == board[2][2]  )
   {

        is_winner = true;

   }
    
   return is_winner;
}

int ask_user(std::string message)
{
    int input = 0;

    std::cout << message << "\n";

    std::cin >> input;

    return input;
}


void set_board() 
{
   board[0][0] = '1';
   board[0][1] = '2';
   board[0][2] = '3';
   board[1][0] = '4';
   board[1][1] = '5';
   board[1][2] = '6';
   board[2][0] = '7';
   board[2][1] = '8';
   board[2][2] = '9';
   
}
void draw_numbered_board() // int location, int square_state )
{

    std::cout << " | " << "---"       << " | " << "---"       << " | " << "---"       << "\n";
    std::cout << " | " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    std::cout << " | " << "---"       << " | " << "---"       << " | " << "---"       << "\n";
    std::cout << " | " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    std::cout << " | " << "---"       << " | " << "---"       << " | " << "---"       << "\n";
    std::cout << " | " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    std::cout << " | " << "---"       << " | " << "---"       << " | " << "---"       << "\n";
}

char pick_state( int square_state )
{
    char temporary_state_holder;

    switch(square_state)
    {

        case TTT_X:
            temporary_state_holder = 'x'; // TTT_X; // " X "; 
            break;

        case TTT_O:
            temporary_state_holder = 'o'; //TTT_O; //" O "; 
            break;

        case TTT_BLANK:
            temporary_state_holder = ' '; //TTT_BLANK; //"   "; 
            break;

        default:
            std::cout << "Error: Bad input. Quitting\n" << std::endl;
            break;
    }

    return temporary_state_holder;
}



void change_square_state( int user_location_pick, int user_state_pick)
{
    
    switch(user_location_pick)
    {
        case 1:
            board[0][0] = pick_state(user_state_pick);
            break;

        case 2:
            board[0][1] = pick_state(user_state_pick);
            break;

        case 3:
            board[0][2] = pick_state(user_state_pick);
            break;

        case 4:
            board[1][0] = pick_state(user_state_pick);
            break;

        case 5:
            board[1][1] = pick_state(user_state_pick);
            break;

        case 6:
            board[1][2] = pick_state(user_state_pick);
            break;

        case 7:
            board[2][0] = pick_state(user_state_pick);
            break;

        case 8:
            board[2][1] = pick_state(user_state_pick);
            break;

        case 9:
            board[2][2] = pick_state(user_state_pick);
            break;

        default:
            std::cout << "Error: Bad input. Quitting\n" << std::endl;
            break;
    }

}

void list_options()
{
        std::cout << "1. Draw X\n";
        std::cout << "2. Draw O\n";
        std::cout << "3. Draw blank\n";
}



























