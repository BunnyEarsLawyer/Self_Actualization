//
// Structure example
// Asks for 5 player's names and skill levels
//

#include <iostream>

//
// User should not enter a string for a number 
// User should not enter a number for a string 
// Values cannot overflow
//
struct PlayerInfo
{

	int skill_level;

	std::string name;

};

int main()
{
	//
	// Like normal variable types, 
        // You can make arrays of structures
	//

	PlayerInfo players[5];

	for(int ii = 0; ii < 5; ++ii)
	{
		std::cout << "Enter name for player: " << ii << "\n";
		
		std::cin >> players[ii].name;

		std::cout << "Enter skill level for player: " << ii << "\n";

		std::cin >> players[ii].skill_level;
	}


	for(int ii = 0; ii < 5; ++ii)
	{
		std::cout << "Player "                << players[ii].name 
		          << " has a skill level of " << players[ii].skill_level
                          << "\n";
		

	}

}
