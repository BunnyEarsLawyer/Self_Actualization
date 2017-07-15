Using Pointers:

- Remember how to think about memory

- This chapter is about syntax

<type> * <pointer name>

E.g.
int * pointer_that_points_to_integer;

int * p_points_to_integer;

- Rather than having a name for a pointer for each type.
You tell the compiler what kind of data is at that address.

double * P_points_to_double;

- Placing & (ampersand) in front means 'To get the address of' 

int x;
int *p = & x;
*p = 2;        // intialize x to 2


- 2 things to do:
1) request the memory location the pinter stores
2) request the value stored at that memory location
   A.K.A 'dereference the pointer'

Vocab
- 'dereference the pointer'
 
- You cannot change the address of a variable.
 
- Summary
-- A pointer stores an address, so when you use the bare pointer, you get that address back. You have to add something extra, the asterisk in order to retrieve or modify the value stored at the address. 

- If you get confused, draw box-and-arrow diagrams.

Uninitialized pointers and NULL:
- If p_int was not intialized to point to a memory address, it can point to anything!
- Nasty bug: overwritting memory held in another variable or crashing your program.
- If you need to have a pointer NOT initialized use the value NULL ( in C++0x = C++ 2008 or 2009) 
or nullptr (in C++ 11 = c++0B)
- Use nullptr not NULL!
// IMPORTANT: b/c nullptr is always a pointer type. 0 (aka. C's NULL bridged over into C++) could cause ambiguity in overloaded function resolution, among other things. 
// Source: https://stackoverflow.com/questions/20509734/null-vs-nullptr-why-was-it-replaced

#-------------------------------------------------
References

When you need some pointer features but not their full power

Syntax: Put ampersand symbol in front

int & ref; // @ non-compliant if it 
           // does not refer to a valid address

int x = 5;
int &ref = x; // @ compliant

Vocab:
reference = a variable that refers to another variable, shareing the same backing memory.

- Think of references as stripped down pointers that don't need asterisk and ampersand syntax to use the referred-to value

- When you use a reference, you get the value of the refrenced memory rather than the address of that memory.

- The actual memory of ref has a pointer to the memory of the x variable.

- Refs are useful to pass structures w/out passing the whole structure nor worry about NULL.

E.g.

void swap ( int & left, int & right)
{

    int temp = right;
    right = left;
    left = temp;

} 

IMPORTANT: Using references is much simpler than the 
way using pointers.

// Behind the scenes, the compiler uses pointers
to store the references but the dereferencing is 
done for you. 

#-------------------------------------------------
References vs. pointers

  - Use references when you need to refer to a variable
   by multiple names.

e.g. passing into a function
e.g. function modifying input parameters.

  - References are not as flexible b/c they must always
    be valid

  - There is no way to indicate NULL
  -  You can't build sophisticated data structures using
     references
  - Once a reference is initialized, you can't change it.
  

The pattern of using a reference in a function 
almost always looks like this:

void (myStructureType& arg)   













   
