Pointers

Up until now we had fixed amount of memory (decided upfront)

Amount of memory allocated is chosen at compile time.
E.g. you create a variable, a fixed amount of memory is allocated to store what the variable contains.

Even though the array can hold a lot of memory, it is also fixed.

Pointer = a variable that can refer to the memory that stores variables

E.g. When you e-mail someone a webpage, you send them a link to it instead of downloading the 
entire page and sending it to them.

A pointer stores the location (the address) of some other data.

Vocab
- pointer
- address

You actually have already seen a pointer!

When you pass an array into a function it did not get copied.

--------What is memory? -----------

E.g. excel spreadsheet with only one column

Memory = large number of sequential data.

- Each "cell" can store 1 byte (256 possible values, 0-255)

- Each "cell" in memory has an 'address' to identify it

- This address is the value that the pointer stores

- Memory addresses here are identified in steps of 4 b/c most data takes up to 4 bytes 

- *****TRUE FOR 32 bit matchines*****

  0    4    8    12   16   18
------------------------------
| ?? | 16 | ?? | ?? | ?? | ?? |
------------------------------

- Memory with 6 variables of 4 bytes each 
(Memory addresses are usually written in HEXADECIMAL form, we will use regular numbers)

Vocab
- Hexadecimal

- Memory at address '4' stores a value that could be another memory address '16' 
- ?? indicates unknown value but there is always something in the address.

-------------------------------------------------------------------------
Sidenote:
- 32 bit machine
   - 32 bits = 4 bytes
   - most native CPU operations take values that are 4 bytes in size
   - some variables are larger than 4 bytes, like doubles
- Hexadecimarl is like this 0x10ab0200. 
   - The '0x' means it's hexadecimal
   - A-F are the digis 10 to 15 
-------------------------------------------------------------------------

Variables vs. addresses--------------------------------------------------------------------------

- A variable is the representation of a value
- That value is stored at a particular location in memory, a particular memory address.
- The commpiler uses memory addresses to implement the variables in your program
- Pointers are a special kind of variable that lets you store the address that 
"backs" another variable.

- Once you have the address of a variable, you can go to that address and retrieve the 
data stored in it.

- If you have a huge piece of data, it is more efficient to tell it where it is using the address.

(How are structures defined and stored in memory, to create many Spaceships?)

- The most important function fo pointers is to enable you to get MORE memory from the 
Operating System.

-------------------------------------------------------------------------
Sidenote:
- OS (operating system)
  - The operating system does manage memory but it is different "layers" of code
    that handle memory. The OS is one layer.
  - Using OS for simplicity.
-------------------------------------------------------------------------

 Vocab
- Pointer can mean to 2 things
  Pointer = A memory address itself
  Pointer = A variable that stores a memory address

- Usually this distinction isn't really that important. If you pass a pointer variable to a function, you are passing the value stored in teh pointer (The memory address)

Vocab
- address = memory address
- pointer = variable that stores a memory address
- 'A variable stores the adderss of another variable' = it is 'poiting to' that variable

Memory layout --------------------------------------------------------------------------

You have a great deal of memory avaiable. That memory is structured.

- Some parts of the memory are already in use. E.g. to store the variables that you declare
in the functions that are currently being executed. This is called the STACK.

Vocab
-Stack

- The stack name comes from the fact that if you make several function calls, the local variables for each function "Stack up" on top of each other in this part of memory. 
- All the variables we have worked with so far have been stored on the STACK.

- A second part of memory is the free store (also known as HEAP)

Vocab
-Heap

- The HEAP is unallocated memory that you can request in chunks.
- The OS manages this part of memory. 
- Once a piece of memory is given out, it should only b e used by the original 
code that allocated the memory. 
- Or...by code to which that address is provided by the memory allocator.
- Using POINTERS will allow you to gain access to this memory.

- Being able to access HEAP memory is powerful, but with great power comes great responsibility.
- Memory is a scare resource 
- Each piece of memory you have allocated from the free store should eventually be released 
back to the free store (HEAP) 

Vocab
- owner = the code responsible for releaseing a particular piece of memory when it no longer needs it. 
E.g. Space shooter game, if a ship is destroyed, the code that owns the memory should return it to the free store so it can be given out to other code.

Vocab 
- memory leak = causes slowdowns and crashes even

- C++ will never free memory you have explicitly allocated while your program is still running unless you explicitly request it.

- If you write a function that takes a pointer, you should document whether the function takes owenership of the memory or not

- Crashes are good things. Crashes caused by accessing invalid memory are easier to diagnose than buts that happen if you write bad data into valid memory. 

E.g. What if you create a random number, and tried to access the memory address using that number. You don't know who allocated that memory and it might even be the stack itself!

Vocab
- invalid memory

----------Invalid Pointers

- one way you can use invalid memory is to use a pointer without initializing it.
- The pointer will have random data inside it if you don't initialize it. 
- Result: CRASH or DATA CORRUPTION

 
----------Memory and arrays

- Going past the end of an array is a problem b/c you don't know what's there.

----------Advantages and Disadvantages of Pointers
PROS
- You don't have to make a copy
- You don't have to worry if you have the latest version.
CONS
- The thing might be moved, or deleted. To avoid this, must keep track of whether anyone 
else might be using it.


Very similar to a link to a webpage.

However, a pointer is another type of variable. 
























































































































