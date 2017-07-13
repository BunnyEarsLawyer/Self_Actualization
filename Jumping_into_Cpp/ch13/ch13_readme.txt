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
