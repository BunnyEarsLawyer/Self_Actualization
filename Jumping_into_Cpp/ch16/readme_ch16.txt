Recursion

- Algorithms based on looping.

Vocab
- Recursion = Another way that involves repeated functions calls

- A function that calls itself
- More powerful than looping
- It can make some programs that are nearly impossible to write with loops nearly trivial!

E.g. applied to linked lists and binary trees.

--------------------
How to think about recursion: 

- Image recursive functions as a process where one of the instructions is to "repeat the process"
- It makes it easy to express ideas where the result of the recursive call 
  is necessary to complete the task.
- E.g. Build a wall 10 feet tall. 
       First build a wall 9 feet tall then add 1 row.

  build_wall
    if the height is greater than 1, first call yourself to build a lower wall.
    Then add 1 row

----------------------------------------
  void buildWall (int height)
  {
     //
     // Condition where the function will not call itself
     // 'base case'
     //
     if (height > 0)
     {
        buildWall( height - 1 );
     }
     addBrickLawyer();
  }
----------------------------------------

Vocab
- base case

- It's trippy at first. But think about the physical process of building a wall.

"to put bricks here, I need a wall one brick shorter"
Eventually you say ...
" I don't need a smaller wall; I can build on the ground" // That's the base case.

- It is like 'top-down design process' = break the big problem into smaller sub-problems

- When a function has called itself, it is ready to go to the next line after the call site when the call returns.
- After the recursive call returns, the function can still perform operations and call other functions! E.g. function to add a layer of bricks.

How would you write a function to output 123345678987654321?
Solution: Print the number twice, once before the function recurses and one after.

Another way to think: the function first prints out the sequence 1-9, each time calling printnum() again.

When the base case is reached, printnum will return to each recursive call, printing the numbers out again in the order the functions returned.

--------------------------------------
Recursion and data structures

- A data structure that contains smaller version of teh same data structure.

E.g. Linked Lists

A linked list points to a first node, which points to another smaller linked list, etc.

Each node points to another node that is the start of "the rest of the list"

  If we are at the end of the list, return NULL.

  Else if the current node is the target it, return it.

  Else, repeat the search.

- The promise of what a particular function will do, is the contract of the function.

Vocab 
- contract

E.g. node* search( node* list, int value_to_find);

" If the current node is the one we want, return it;
otherwise, the contract of the search function is to find a node in the list----let's use that to look through the rest of the list " 

- Important to call the search function on the remainder of the list, NOT the whole list again.

Recursion will work if:

1) Come up with a way to solve the problem by working witht he solution to a smaller version of the same problem.
2) Solve the base case.

E.g. search() solves 2 possible base cases: We found the node, we are at the end.

Factorial Example!

Factorial(x) = x*(x-1)*(x-2)...*1

Factorial(x) = 
    If (x ==1 ): 1
    Else:        x * Factorial(x-1) 

Factorial is multiplying the current value times the factorial of a smaller value.
Each call to factorial makes x smaller so eventually we will reach the base case.

- Notice: we solve the sub-problem, then take the result and do something with it.

- Search linked list: return the result of solving the sub-problem.

Recursion can be used both ways:
- Hand full responsiblity for solvinga problem by making a recursive call
- Get the result of solving a sub-problem and then use that result to do more computation

Loops and recursion

// Iterative solution
node *search(node *list, int value_to_find)
{
    while(1)
    {
        if(list == nullptr)
        {
             return nullptr;
        }
        if(list->value==value_to_find)
        {
             return list;
        }
        else
        {
             list = list->next;
        }
    }
}

// This makes the same check as the recursive version.
// The difference is that instead of using a recursion, the code uses a loop, instead of making a recursive call, it shortens the list each time, by setting the list to point to "rest of the lsit"

Vocab 
- tail recursion = when the recursive call is the last thing the function does (tail of the function)

int factorial (int x)
{
    while(1)
    {
        if(x==1)
        {
            return 1;
        }
        // What to put here?
        // return x * factorial(x-1);
    }
}

// How to translate recursion to an iterative solution:
Here we are not taking ther esult of a sub-problem, instead we are 
computing in the opposite order.

1*2*3*4*5

int factorial(int x)
{
    int cur = x;
    while(x>1)
    {
        x--;
        cur *= x;
    }
    return x;
}

// Compare to:
int factorial (int x)
{
    if(x==1)
    {
        return 1;
    }
    return x*factorial(x-1);
}

5*4*3*2*1

Step 1.  x = 5, return = 5*(factorial(4)), next input (x-1) = 4
Step 2.  x = 4, return = 4*(factorial(3))
Step 3.  x = 3, return = 3*(factorial(2))
Step 4.  x = 2, return = 2*(factorial(1))
Step 5.  x = 1, return = 1

All: 5*4*3*2*1

- Both recursive and iterative solutions are possible but they have different structures.

- Sometimes finding the iterative solution is much harder! See next examples.

-------------------------------------
The Stack

- How function calls work

- All the info that a function uses is stored internally on the stack
E.g. stack of plates

- Instead of plates you have 'stack frames' 

- When a function is called, a new 'stack frame' is placed on top to keep all local variables in there. When it calls another function, the original stack frame space is kept, a new stack frame is added to the stop to give the new function a function space of its own.
- The currently running function always uses the stack frame at the top of the stack.

Vocab
- stack
- stack frames

E.g.
----------------
Variables in main
----------------

E.g. Main calls another function
----------------
Variables in 2nd function
----------------
Variables in main
----------------

E.g. The 2nd function calls another function
----------------
Variables in 3nd function
----------------
Variables in 2nd function
----------------
Variables in main
----------------

- Every new function call creates a new stack frame.

E.g. The 3rd function returns
----------------
Variables in 2nd function
----------------
Variables in main
----------------

E.g. The 2nd function returns
----------------
Variables in main
----------------

What does the stack frame contain?
- Variables used in the function
- arguments the function took
- line of code the function should return to

- Recursively calling the function will create a new stack frame for the new call.
Even if it's the same function. That's why recursion works--every function has its won unique stack frame, arguments and variables. Each function works a smaller version of the rogiinal problem.  


E.g. You are working on a project, you go get dinner, you write down some notes to help you remember where you were in the project, so that after dinner you come back and finish.

The stack allows the computer to keep extremely detailed notes about what it was doing at any time.


Good technique: Each function is shown on top of the faction that called it!

E.g. Build wall stack frames:

buildWall(x=0); // Build on the gnd
buildWall(x=1);
buildWall(x=2);
main()

Remember: In factorial, the stop of the stack is the last call.
Step 1.  h = 5, return = 5*(factorial(4)), neht input (h-1) = 4
Step 2.  h = 4, return = 4*(factorial(3))
Step 3.  h = 3, return = 3*(factorial(2))
Step 4.  h = 2, return = 2*(factorial(1))
Step 5.  h = 1, return = 1
Step 6.  h = 0, return = 0
----------------------------------------------------------
The power of the stack

- KEY VALUE: You get a stack of function calls rather than a single stack frame.

- Recursive algorithms take advantage of all the information stored in each stack frame.

- In comparison, only gets one set of variables.

- A recursive function can wait for a recursive call to return and pick up wher eit left off.

- A loop that works waits this way youd have to implement its own version of a stack.


Disadvantages of recurssion:
- Stack is fixed size, you can't have limitless recursion.
- Stack overflow = When the program crashes b/c it uses up all the stack space

Vocab
- stack overflow

This crash, stack overflow, happens b/c of a bad base case. E.g. In the factorial example, passing a -1 would almost certainly overflow the stack. Try it :) It won't damage your computer.

Also, the larger your function is, the fewer recursive calls you can make.

---------------------------------
Debugging stack overflows.

- Find which function, or group of functions, is repeatedly adding new stack frames.

- Sometimes, you have mutual recursion, where 2 functions call each other!

Vocab
- mutual recurssion

E.g. factorial for even and odd, both should check for negt. numbers

Performance
- Recursion requires making many function calls. Each function calls needs a stack frame and to pass arguments. This adds overhead.

- In almost all cases, it's not significant on modern computers. If you have code that is very frequencly executed (millions or billions) you might start to notice the overhead.

Taking stock of recursion
- Recursion makes it possible to create algorithms that solve problems by breaking those problems into smaller versions.

Recursion also provides more power than loops b/c they maintain a stack holding the current state of each recursive call, allowing the function to continue processing after getting the result of the sub-problem.

A recursive implementation of an algorithm will often feel more natural.

Rules of thumb, use recursion when....
1. The solution to a problem requires breaking down the problem into smaller versions of the same problem.
2. The data structure you have is recursive (like a linked list)

Rules of thumb, use loops when....
1. It's obvious how to solve the problem with a simple loop.
2. When you use a data structure that's indexed by a number, like an array.


