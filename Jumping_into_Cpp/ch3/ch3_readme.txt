What if you want to interact with your user?

- You need *input*: information that comes from outside the program
- You need a place to store that input, 
- In programming, where you store data are called **variables**
- There are different types of data, e.g. numbers vs. letters. 
- You tell the compiler what type of data your **variable** with a word called **type**

------------------------------------------------------------------------------------
Most basic **types**: char, int, double

char = 'a' 'b' 'c' ..
int = -255 ...,-1, 0, 1,2,...255
double = 3.24155554

------------------------------------------------------------------------------------
cin.get() = to trow away the Enter key that the use enters, you may not need it.
------------------------------------------------------------------------------------
Reading and printing variables gets boring.
- Let's add the ability to modify variables and
  - Assignment operator =
- change the program behavior based on the values of variables
- You can even do arithmetic operations (+, -, /, *)

------------------------------------------------------------------------------------
Shorcut operations

- x++      // Incrementing operator '++' adds 1 to x 
- x += 5;  // Adds 5 to x

------------------------------------------------------------------------------------
Common errors declaring variables
- Cannot name several variables with the same name. E.g. int my_val and double my_val
- You have to declare a variable. 
Bad code
- You must assign a value to a variable. There is no default value.

Other
- Everything has case sensitivity
- Name things with meaningful and descriptive names

------------------------------------------------------------------------------------
Storing strings
- A char   stores one character.
- A string stores multiple characters.

String is NOT a built-in data type. You have to include its **header file**.
Like this: 
```
#include <string>
```
This is b/c string is not built-in directly in the compiler. **WOW**
but they are part of the C++ standard library (re-usable code)

- You can **concatonate**, or append two strings together with the + sign.
- If you want a whole line use
```
getline()
```
You can also use it to get it until a special character, like a comma.
```
getline(std::cin, my_string, ',');
```

**input buffer**

------------------------------------------------------------------------------------
Advanced.

- bit    = 0 or 1  =   n/a   = 2 possibilities
- byte   = 8 bits  = 1 bytes = 256 possibilities
- char   = 8 bits  = 1 bytes = 256     " 
- int    = 32 bits = 4 bytes = 4 billion possibilities 
- float  = 32 bits = 4 bytes =         "
- double = 64 bits = 8 bytes = 92 quadrillion 

// **float** the older one that could store decimal valued numbers. Limit of 6 spaces and the period floats. e.g. 12.3456 or 1234.56
// **double** use it, it's ok. Back in the day programs would go to great lenghts to save space but that's not longer the case.















































