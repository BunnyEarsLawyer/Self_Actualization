Dynamic memory allocation 

IMPORTANT: THIS IS OLD, READ UP ON C++ 11

-----------------------------------------------------------------------
Vocab 
- Dynamic memory allocation = means requesting as much (or as little) memory
                              as you need while your program is running.

- Your program will calculate the amount of memory it needs, instead of working
  with a fixed set of variables with a particular size.

Syntax:

- Keyword 'new' = initializes pointers with memory from the free store.

    // Takes in an integer, returns enough memory to hold an integer.
    int *p_int = new int;   

Vocab
- Free store = chuck of unused memory
- 'new' operator

SUPER-IMPORTANT: p_int must 'free' the memory, return it back.

Syntax:

    delete p_int;
    p_int = NULL; // good practice, if you don't set to NULL program crashes
                  // when you dereference this pointer

Running out of memory:

- call to 'new' will 'throw and exception' b/c the system is out of memory

Vocab:
- 'throw exception'
- runtime =  when program runs

- Always free the memory you allocate, don't worry about the fact new might fail.

Pointers and arrayws:

- Q: how do you use new to get mroe memorY?
- A pointer can be treated like an array 
- An array is a series of values laid sequentially in memory
- You can actually create a new array dynamically from the free store.
  At runtime, determines the amount of memory you need.

- Arrays are not pointers but they can be asssigned to pointers.
- The pointer will point tot he first element of the array.
E.g. You can assign a char variable to a variable of type int b/c 
     the compiler knows how to do the conversion.

    int numbers[9];
    int* p_numbers = numbers; 
    p_numbers[4] = 0;

    // 
    // Dynamically allocate an array of memory using new and
    // assign that memory to a pointer
    // User provided how much memory is needed.
    // 
    int count_of_numbers;
    cin >> count_of_numbers;

    int *p_numbers = new int [ count_of_numbers ];

    // Don't forget! Free memory
    delete[] p_numbers;

See: resize_array.cpp
-----------------------------------------------------------------------
Multidimensional arrays:

- Good excercise to understand pointers. However, you need pointer arithmetic first.

Vocab:
- Pointer arithmetic 

- From author: If you can understand this section you will spend less time on the rest of the book.
Big payoff!


Memory addresses and how to thing about them:

- Pointers represent memory addresses
- Memory addresses are just numbers
- You can, then, do math with them 
- Why?
- B/c there are times when you want to write a block of memory and you know the *exact*
  offset to place a value
- No, it's not gobbledygook. You've already run into this: arrays!

E.g.
   int x[10];
   x[3] = 120;

- You are performing POINTER ARITHMETIC to set the 3rd memory slot the the value 120.
- The bracket is just 'syntatic sugar'

Vocab:
- 'syntatic sugar' = simplified syntax 
- 'sizeof' = gives the size, in bytes, of a variable type
- 'slots of memory' = these are not bytes!

E.g.
- You can do the same thing with....

   *(x + 3) = 120;

// Me: x points to the beginning of the array.
//     x + 3 makes it point to the 4th element
//     * dereferences the pointer so you change the value

- Let's break this apart
- Confusingly, this is NOT adding 3 to the value of x
- It is adding 3 * sizeof( int ) 
- It is adding 3 slots of memory
- By the way, you can subtract pointers to compute their distance
    - The distance is teh number of slots, not number of bytes.
    - You can't subtract pointers of different types for this reason.
    - It is rare to subtract pointers. 
    - You can't add pointers, you can only add an offset.
    - Isn't interesting that adding and subtracting result in different types
      of values?
- Adding increments of the variable size prevents you from accidentally 
  using pointer arithmetic to write (or read) b/t two values.

------------------------------------------------------------
Understanding Multi-dimensional arrays:
- Again, big payoff to understand this!
- Odd curiosity: When you declare that a function takes a 2-D array you 
                 need to provide the size of only the 2nd part of the array. Why?
E.g.
    - You can provide both sizes
    int my_function( int array [2][2] );// @ compliant

    - One size
    int my_function( int array [][2] ); // @ compliant

    - But never omit both
    int my_function( int array [][] );  // @ non-compliant

- B/c 2-D arrays are layed out flat in memory!
- The compiler transforms an array access, like array[3][2], into a position in memory

- [0][0][0][0]       // how you think, x marks array[3][2]
  [1][1][1][1]
  [2][2][2][2]
  [3][3][x][3]

- [0][0][0][0][1][1][1][1][2][2][2][2][3][3][3][3]  // in reality
- [4 integers][4 integers][4 integers][+][+]   

- Go 3 rows down, with each row being 4 integers wide (4*3 slots down)
- Then add 2 more integer slots (go to 3rd element in last row)

- array[3][2] turns into the following pointer arithmetic...

  *(array + 3 * < with of array> + 2)

// Me: array points to the beginning of the array (0th element)
//     before adding, 3 * <with of array> takes you to last row (layed out flat, 13th element)
//     + 2 makes it point to the 3th box in the last row (15th element)
//     * dereferences the pointer so you change the value

- The 2nd dimension of an array is the width
- You can't do the same math with the height b/c of how the data is layed out physically in memory.
- Hence, the second dimension must always be specified.
- In fact, for multi-dimensional arrays, you MUST specify all dimensions except the first (height)!

What if you want to dynamically allocate a 2-D array?
- The second value is hard-coded in the prev example.
- You need, pointers to pointers

Vocab 
- 'pointers to pointers' 
------------------------------------------------------------
Pointers to pointers 












