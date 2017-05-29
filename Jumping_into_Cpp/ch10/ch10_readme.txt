Arrays

- Answer the question of how to easily store lots of data
- Numbered list


Vocab
- element of the array
- index
- offset

Syntax:

//declare
int my_array [6];

//access the 3rd element (box)
my_array[3]


- indexing starts at 0
[val 0] [ val 1] ...[val x]


e.g.
// set the 3rd element to contain the number 2
my_array[2] = 2; 


Remember: How would you shuffle a 52 card deck?

Uses:
- Represent ordered things 
- Store sorted values
- Represent multidimensional data

E.g. 2-D array

int tic_tac_toe_board[3][3]

// two indices: row and column

[0][0] [0][1] [0][2]
[1][0] [1][1] [1][2]
[2][0] [2][1] [2][2]

- To pass a single-dimensional array just pass it, no need to tell it a size.

If you are defining an array, the compiler needs to create space for it when you pass
it into a function. It just passes the original array so need for size.
Any changes made to that array will also change! 

- You need to give a size to a function when you pass it a multidimensional array.

e.g. Weird

int check_tic_tac_toe( int board [][ 3 ] );

// For now just remember you don't need to pass the first dimension.

// See chapter on pointers later.

- Never try to write outside of the array.

E.g.  BAD CODE

int my_array [10]; // 0 to 9

my_array [10] = 4; // BAD, tries to write on an 11th item

- The compiler will not tell you about these bugs!!


-----------sorting arrays ---------------

- How would you take 100 values and sort them?

Most people naturally sort by first finding the lowest value in a list, then move it tot eh beginning. 
They then find the second lowest value, move it after the first, and so on.

This is known as *** insertion sort ***.

Vocab
- insertion sort
- Batch 


- As a programmer, you want to decide which algorithm to use based on the problem. In this case,
insertion sort works well for 100 values but if you had millions of users, it's too slow.

Think of how google works. Serving millions of users everyday.

If you want a program that can store and work with unlimited amounts of data, 
a fixed size array won't cut it.








 






















































