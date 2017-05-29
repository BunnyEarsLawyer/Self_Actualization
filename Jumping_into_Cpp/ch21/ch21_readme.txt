Breaking programs into smaller pieces

Why?
- Making changes is cumbersome in a single file. You'll get lost
- Using more than one file makes it easier to design the program.
- Each header file will contain the specific interface for the associated source.
  It will not be possible for other files to use functions or data structures 
  that aren't defined in the header file. 

Understanding C++ buil process

1 preprocessing
2 compilation
3 linking

- build = the total process to make source code into an executable  

--------Preprocessing-----------

- The compiler runs the C preprocessor
- C preprocessor makes textual changes to the file before the compile step
- C preprocessor understands the 'preprocessor directives', 
  commands intended for it and not the compiler
- All preprocessor directives start witht he pound sign #

E.g. #include <iostream>  

// Tells the C-preprocessor to grab the file isotream 
   and be pasted into the file before the compiler sees it!
 
- 'Macros' are strings of text that is replaced by another, usually complicated, string of text

E.g. #define MY_NAME "Alex abcdasdfa asdfacbqwe" 

// Lets you use MY_NAME instead of that long string
// Macros centralize information
   Let's you change only that line if you want to change it everywhere it is used

E.g. #define VERSION 7 

- IMPORTANT: Because the preprocessor runs before the compiler processes the code, 
  it CAN ALSO BE USED TO REMOVE CODE.

// Sometimes you want to compile certain code in a debugging build. ** OOH!!! **
// Then you can define the macro

E.g. #define DEBUG

#ifdef DEBUG
    std::cout << my_value << std::endl;
#endif

// Simply comment out the #define line to avoid printing out

- You can also include something if it is NOT defined.

E.g. #ifndef
 
Vocab
- preprocessor
- proprocessor directives
- macros

--------Compilation-----------


--------Linking-----------
