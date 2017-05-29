Switch Case and Enum

--Switch Case--
Switch case = replace if-statements that compare a single value to several integral values.
Integral value = value that can be expressed as a positive integer (char and int)

e.g.
switch (variable)
{
  case 1:
    //code
    break;     // If this wasn't here, it would fall-through
  case 2:
    //code
    break;
  default:
    //handles unexpected values
    break;     // `break;` goes out of the switch statement only. Even if it's on a loop.
}

Falling through = it can happen if you don't include the `break;` statement

Some illegal things:
e.g. 
int a = 10;
int b = 10;

switch(a)
{
    case b:       //Cannot compile: Error 'b cannot appear in a constant expression'
        //code 
        break;
}

Q: Why bother with Switch Cases if if-statements can do the same thing?
A: B/c in switch cases it is clear one variable controls the code flow 
but in if-statements, you have to read each if-statement carefully.


--Enum--

enum Rainbow_Color
{
    RC_RED;      // Default value is 0
    RC_ORANGE;   // Default value is 1
};

enum Rainbow_Color
{
    RC_RED    = 10;    // Default value is 0
    RC_ORANGE = 255;   // Default value is 1
};



Enums are good for working with fixed kinds of input.
Switch-case statements are good for working with user input.
However, neither can deal with more than a few input values at once.


---------------------------------

Other cool notes:

I separated the main function into a main.cpp
and the functions into tic_tac_toe.cpp

To include it the correct syntax is with "" not <>
e.g. #include <mystuff.cpp> //@non-compliant
e.g. #include "mystuff.cpp" //@compliant








































