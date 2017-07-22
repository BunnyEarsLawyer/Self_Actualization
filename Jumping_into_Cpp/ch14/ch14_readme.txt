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


























