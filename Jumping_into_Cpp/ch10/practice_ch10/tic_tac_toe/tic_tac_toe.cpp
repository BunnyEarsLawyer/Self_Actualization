// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

//
// Global variables
//
std::string p1 = " 1 ";
std::string p2 = " 2 ";
std::string p3 = " 3 ";
std::string p4 = " 4 ";
std::string p5 = " 5 ";
std::string p6 = " 6 ";
std::string p7 = " 7 ";
std::string p8 = " 8 ";
std::string p9 = " 9 ";

//
// Board 3x3
//
std::string board[3][3];

enum SquareState
{
    TTT_X     = 1,
    TTT_O     = 2,
    TTT_BLANK = 3

};

//
// Functions are called as needed 
//

int ask_user(std::string message)
{
    int input = 0;

    std::cout << message << "\n";

    std::cin >> input;

    return input;
}


void set_board() 
{
   board[0][0] = " 1 ";
   board[0][1] = " 2 ";
   board[0][2] = " 3 ";
   board[1][0] = " 4 ";
   board[1][1] = " 5 ";
   board[1][2] = " 6 ";
   board[2][0] = " 7 ";
   board[2][1] = " 8 ";
   board[2][2] = " 9 ";
   
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

std::string pick_state( int square_state )
{
    std::string temporary_state_holder = "   ";

    switch(square_state)
    {

        case TTT_X:
            temporary_state_holder = " X "; 
            break;

        case TTT_O:
            temporary_state_holder = " O "; 
            break;

        case TTT_BLANK:
            temporary_state_holder = "   "; 
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



























