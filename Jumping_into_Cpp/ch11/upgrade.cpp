//
//
//

#include <iostream>

//
//
//
struct EnemySpaceShip 
{

	int x_coordinate;

	int y_coordinate;

	int weapon_power;

};


EnemySpaceShip getNewEnemy()
{
	EnemySpaceShip ship;

	ship.x_coordinate = 0;

	ship.y_coordinate = 0;

	ship.weapon_power = 20;

	return ship;	

}

//
// When a structure is passed to a function, it will be copied
// (just like when we return a structure) so any changes made to the structure 
// will be lost! That is why the function needs to return a copy of 
// the structure after modifying it.
//
EnemySpaceShip upgradeWeapons( EnemySpaceShip ship)
{
	ship.weapon_power += 10;
	return ship;
}

int main()
{
	EnemySpaceShip enemy = getNewEnemy();
	enemy = upgradeWeapons( enemy );
	//
	// What if you wanted to created an unknown number of enemies?
	// How would you keep track of them and where would you store them?
	// Right now we only have fixed sized arrays.
	//

}
