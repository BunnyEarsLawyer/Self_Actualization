//
//
//

#include <cstdlib>
#include <ctime>
#include <iostream>


struct EnemySpaceShip 
{

	int x_coordinate;

	int y_coordinate;

	int weapon_power;

};


EnemySpaceShip getNewEnemy()
{
	EnemySpaceShip ship;

	ship.x_coordinate = 1;

	ship.y_coordinate = 1;

	ship.weapon_power = 20;

	return ship;	

}

//
// Assigns random number between low and high numbers
//
int randRange(int low, int high);

//
// When a structure is passed to a function, it will be copied
// (just like when we return a structure) so any changes made to the structure 
// will be lost! That is why the function needs to return a copy of 
// the structure after modifying it.
//
EnemySpaceShip upgradePosition( EnemySpaceShip ship)
{
	ship.x_coordinate = randRange(1,1024);
	ship.y_coordinate = randRange(1,768);
	return ship;
}

int main()
{

	int MAX_X = 1024;
	int MAX_Y = 768;
	// Set up for getting a random number
        srand( time(NULL) );
        // Obtain an enemy spaceship and update to random position
	// Assumption: size of screen is 1024 to 768 pixels

	EnemySpaceShip enemies[5];

	enemies[0] = getNewEnemy();
	enemies[1] = getNewEnemy();
	enemies[2] = getNewEnemy();
	enemies[3] = getNewEnemy();
	enemies[4] = getNewEnemy();

	for(int ii = 0; ii < 5; ++ii)
	{
	    if ( enemies[ii].x_coordinate < MAX_X && enemies[ii].y_coordinate < MAX_Y )
	    {
	        std::cout << "enemies w/in bounds" << std::endl; 
	        std::cout << " x " << enemies[ii].x_coordinate << std::endl; 
	        std::cout << " y " << enemies[ii].y_coordinate << std::endl; 
	        enemies[ii] = upgradePosition( enemies[ii] );
	    }
	    else
	    {
	        std::cout << "enemies out of bounds" << std::endl; 
	        std::cout << " x " << enemies[ii].x_coordinate << std::endl; 
	        std::cout << " y " << enemies[ii].y_coordinate << std::endl; 
	    }
	} 

}


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
