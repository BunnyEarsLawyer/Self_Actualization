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

EnemySpaceShip* addNewEnemyToList( EnemySpaceShip* p_list)
{
    EnemySpaceShip* p_ship = new EnemySpaceShip;

    p_ship->x_coordinate = 0;

    p_ship->y_coordinate = 0;

    p_ship->weapon_power = 20;

    //
    // Here p_list points to the head of the list
    // The new ship is now the front 
    //
    p_ship->p_next_enemy = p_list;

    return p_list;

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

        EnemySpaceShip* p_enemies;

        p_enemies = addNewEnemyToList( p_enemies );
       
        EnemySpaceShip *p_current = p_enemies;

        //
        // Iterating over a Linked List
        // Only p_current changes, everything else 
        // stays the same
        //
        while ( p_current != NULL )
        {

            upgradeWeapons( p_current );

            p_current = p_current->p_next_enemy; 
            
        }

	//
	// What if you wanted to created an unknown number of enemies?
	// How would you keep track of them and where would you store them?
	// Right now we only have fixed sized arrays.
	//

}
