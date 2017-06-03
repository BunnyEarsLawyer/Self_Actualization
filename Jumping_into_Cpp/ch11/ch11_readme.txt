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


