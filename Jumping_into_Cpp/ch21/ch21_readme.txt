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

Compilation means turning a source code file (e.g. cpp file) into an OBJECT file (.o, .obj)

An object file contains your program in a form suitable for the computer processor to understand 
A.K.A. Machine Language Instructions

- Each source file is compiled separately
E.g. 3 source files become 3 .obj or .o files

- You cannot use the .obj files yet! They have not been linked together. 

Vocab
- object file
- processor
- machine language instructions

--------Linking-----------

Linking means creating a *single* executable file (E.g. .exe or .dll) out of a bunch of object files (.obj, .o) and libraries (.dll)

- Even if you only have one object file, the linking always happens.

- The linker creates an .exe file in the proper format and transfers contents from each .obj file appropriately.

- The linker also takes object files that are defined outside of the object files original source file! 

Great Example: cout << "Hi"  

// The linker takes the function from the Standard Template Library (STL) 
// that defines the function cout. Your source file did not define cout

- The compiler vendor provides the object file for cout
- At the time of compilation, the compiler knew the function call was valid b/c you included iostream header file. (#include <iostream>). 

- Fixup = Since that function (cout) was not part of your cpp file, the compiler leaves a stub at the call site.

- The linker parses through object file (.obj) and at every stub, it finds the correct 'function address' and replaces the stub with the correct address from one of the object files being linked. 

- If a linked cannot find a definition for a function anywhere, it will generate an 'undefined function' error. Even if the compiler let the code throught it doesn't mean it's correct! 

IMPORTANT: The linker is the first place that looks at the whole program at once.


Vocab
- Fixup
- Function address


----------Why separate compiling and linking? -----------

IMPORTANT: Because not every function needs to be defined in the same object file.

You can compile individual source files one at a time and then link them later.

E.g. FrequentlyUpdated.cpp vs. InfrequentlyUpdated.cpp

It saves build time to skip compiling code that doesn't need to be compiled.

E.g. Days to compile, hours to compile

Build = compile + link

Vocab
- Build
- Conditional compilation


You need a tool in order to tell which object file is out of date.

Windows = taken care for you
Mac     = Xcode takes care of it
Unix    = Use make (http://wwww.cprogramming.com/tutorial/makefiles.html)


----------How to split your program accross different files -----------

- Separate your code to take advantege of separate compilation.

E.g.
You have shared code in a program 'Orig.cpp' which you wish to REUSE in a new program.

Step 1. Split out declaration and definition
Step 2. Figure out which functions need to be shared.
Step 3. Move shared function into their new files

See Linked List example








 







