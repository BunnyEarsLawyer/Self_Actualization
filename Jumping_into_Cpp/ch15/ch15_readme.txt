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

- IMPORTANT: The STL actually makes it quite easy to add new elemetns to an array-like data structure, removing its advantage of linked lists. As a result, the vector class is typically a better choice than either a linked list or an array.

----------------------------

Taking stock of linked lists

You'd have to add operations such as: adding elements into
the middle of a list and removing elements.

SECRET: You will never really need to implement a Linked List yourself
You use an STL.

The importance of linked lists is that we will use similar techniques
to create more interesting data structures.

By understanding the linked list you can better understand the tradeoffs.

ADVANTAGES of LINKED LISTS:

- Easily resized or added/removed to, no need to move things.

ADVANTAGE OF ARRAYS:
-  Array lets you choose any element very quickly. Just provide the index.
- On a linked list you'd have to look through every element.
- You can't just into the middle of a linked list :( 
- The time it takes to access an element of the array by its index is 'constant'
  meaning it doesn't change with the size of the array.
- As your list grows, finding an element will become slower and slower

- for the example don't assign numbers to candidates, you might as well 
compare bynames b/c it's not that different in efficiency   

Q: How much space is required for a linked list?
- A linked list starts with a pointer and the actual datum. So it starts with twice of 
 what an array would need.
- Large enormous data structures, taking up twice the amount may be a big deal.
- If you don't know how many elements will be stored, instead of allocating a large
  array, you can allocate a new linked list only when needed.
- You could allocate an array dynamically but it will require you to copy the elements of the array every time you need more memory.   

S: General rules of thumb

- Use arrays when you need constant time access to elements by index
  and you know how many items you need to store in advance

- Use linked lists when you need to be able to continually add new elements.
  or you need to do a lot of insertions into the middle of the list.

