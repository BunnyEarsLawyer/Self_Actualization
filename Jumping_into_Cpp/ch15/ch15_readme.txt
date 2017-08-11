Data Structures with Linked Lists

- More flexible uses of dynamic memory allocation

Vocab
- data structure = a way of organizing data in memory

e.g. array is a linear fashion (simple way)

Value of advanced data structures:

CONS of arrays:
1 - Arrays are 'expensive' operations  
    You have to allocate, then copy your items to it.

2 - Cannot insert data in b/t elements
    If you want to insert 1 item in a list of 1 million, you
    would have to shift 1 million minus 1 items (expensive)

Data structures are all about making efficient ways to store data

ADVATAGES of data structures:

1 - Allow you to think at a higher level
    E.g. instead of saying you need a loop, you say I need a list

2 - Logical way to organize data and a shorthand way to communicate the basic operations that a program needs.


Wouldn't it be great if you could make a data structure where each item of data
told you where to find the next?

Linked list.

E.g. you have a list of Enemy Ships and you want to quickly add and subtract
from that list.


C++ can handle self-reference!

E.g.

------------------------
struct EnemySpaceShip
{

    int x_coordinate;
    int y_coordinate;
    int weapon_power;
    EnemySpaceShip* p_next_enemy; //Pointer to EnemySpaceship
}
------------------------

What if instead of a pointer we wrote this: 
    EnemySpaceShip next_enemy; // EnemySpaceship
? 

We would have a structure that repeated itself infinitely!
It would take all of the computer's memory!!!

- Pointers don't have to point to valid memory.
- A ship that 'might' point to another ship

Pointers & Structures:

- To access the fields of a structure through a pointer use ->

- Each field of a structure has a different memory address. 
Usually a few bytes away from the start of the structure.

- The Arrow (->) syntax computes the offset needed to get that field of the 
structure.

E.g.

(*p_structure).my_field;







