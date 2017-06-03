//
// To compile: g++ main.cpp
//

#include "tic_tac_toe.cpp"
//
// Program starts here 
// Two-player tic-tac-toe that allows two humans to play 
//
int main()
{

    int player_location_input = 0; 

    int player_state_input    = 0; 

    std::string message_to_get_location = "Pick a square from 1-9: ";

    std::string message_to_get_state    = "Pick a state by number (1-3) for the box: ";

    std::cout << " Disclaimer: this game relies on both players to " 
              << " promise not to override each others plays.\n"; 

    set_board();

    draw_numbered_board(); 

    bool is_winner = false;

    for(int ii = 0; ii < 9; ++ii)
    {

	player_location_input = ask_user(message_to_get_location);
	
	list_options();

	player_state_input = ask_user(message_to_get_state);
	
	change_square_state( player_location_input, player_state_input );
                    
	draw_numbered_board(); 
		   
	std::cout << " Change players\n"; 

	is_winner = check_horizontal_lines(); 

  	is_winner = check_vertical_lines(); 

  	is_winner = check_cross(); 

	if(is_winner == true)
	{
		std::cout << "Heyyy 3 in a row. A Winner";
		break;	
	}
	
    }

}



