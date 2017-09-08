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






  
