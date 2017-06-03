Structures

You can sure lots of data in an array but what if you want several types of data
that are associated together

E.g. x,y coordinates of a player in a video game 

int x_coordinates [10];
int y_coordinates [10];

// You would have to remember how they are associated

Structures let you store different variables under the same name

Vocab
- Compound type

struct Spaceship
{
   int x_coordinates [10];
   int y_coordinates [10];
   string name;
}

Spaceship my_ship;
my_ship.x_coordinate = 1;
my_ship.y_coordinate = 1;
my_ship.name         = "Badassium 100"

- Passing structures around. See chapter on pointers to avoid copying values.

- When a structure is passed into a function, it will be copied.
  Any changes you make to the structure in the function will be lost!
  That is why you return a copy back.

E.g. 

ship = upgradeWeapons(ship);

- What if you want to make several ships?

EnemySpaceShip my_enemy_ships[10];

// This is still limited to 10 enemies at once. See chapter on pointers.
