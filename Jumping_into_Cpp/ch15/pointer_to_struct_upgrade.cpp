//
//
//

#include <iostream>
#include <cstddef>

//
//
//
struct EnemySpaceShip 
{

	int x_coordinate;

	int y_coordinate;

	int weapon_power;

	EnemySpaceShip* p_next_enemy;

};


EnemySpaceShip* getNewEnemy()
{
        // 'new' used to allocate memory for a new ship
	EnemySpaceShip* p_ship = new EnemySpaceShip;

	p_ship->x_coordinate = 0;

	p_ship->y_coordinate = 0;

	p_ship->weapon_power = 10;

	p_ship->p_next_enemy = NULL;

	return p_ship;	

}

//
// Before:
// When a structure is passed to a function, it will be copied
// (just like when we return a structure) so any changes made to the structure 
// will be lost! That is why the function needs to return a copy of 
// the structure after modifying it.
//
// Now:
// Passing a pointer
// We can modify what p_ship points to directly 
void upgradeWeapons( EnemySpaceShip* p_ship)
{
	p_ship->weapon_power += 10;
}

int main()
{
	EnemySpaceShip* p_enemy = getNewEnemy();
	upgradeWeapons( p_enemy );
	//
	// What if you wanted to created an unknown number of enemies?
	// How would you keep track of them and where would you store them?
	// Right now we only have fixed sized arrays.
	//

}
