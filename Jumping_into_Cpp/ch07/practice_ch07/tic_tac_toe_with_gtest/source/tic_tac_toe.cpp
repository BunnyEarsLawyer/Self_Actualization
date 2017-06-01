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

enum SquareState
{
    TTT_X = 1,
    TTT_O = 2,
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


void draw_numbered_board() // int location, int square_state )
{

    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
    std::cout << " | " << p1    << " | " << p2    << " | " << p3    << "\n";
    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
    std::cout << " | " << p4    << " | " << p5    << " | " << p6    << "\n";
    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
    std::cout << " | " << p7    << " | " << p8    << " | " << p9    << "\n";
    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
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
            p1 = pick_state(user_state_pick);
            break;

        case 2:
            p2 = pick_state(user_state_pick);
            break;

        case 3:
            p3 = pick_state(user_state_pick);
            break;

        case 4:
            p4 = pick_state(user_state_pick);
            break;

        case 5:
            p5 = pick_state(user_state_pick);
            break;

        case 6:
            p6 = pick_state(user_state_pick);
            break;

        case 7:
            p7 = pick_state(user_state_pick);
            break;

        case 8:
            p8 = pick_state(user_state_pick);
            break;

        case 9:
            p9 = pick_state(user_state_pick);
            break;

        default:
            std::cout << "Error: Bad input. Quitting\n" << std::endl;
            break;
    }

    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
    std::cout << " | " << p1    << " | " << p2    << " | " << p3    << "\n";
    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
    std::cout << " | " << p4    << " | " << p5    << " | " << p6    << "\n";
    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
    std::cout << " | " << p7    << " | " << p8    << " | " << p9    << "\n";
    std::cout << " | " << "---" << " | " << "---" << " | " << "---" << "\n";
}

void list_options()
{
        std::cout << "1. Draw X\n";
        std::cout << "2. Draw O\n";
        std::cout << "3. Draw blank\n";
}



























