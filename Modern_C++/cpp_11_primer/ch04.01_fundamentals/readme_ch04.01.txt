Fundamentals Q&A

Vocab
- unary operators = act on 1
  &  'address of' 
  *  'dereference'
- binary operators = act on 2
  == equality

- 'precedence'
- 'associativity'
- 'order of evaluation'

E.g.
5 + 10 *2.0/2  

Operand conversion

Vocab
- 'Integral promotion'
- integral type
  signed/unsigned char
  bool
  short
  unsigned short
- 'promoted' larger integral type
  int


- When operands have the same signness they are converted to the larger type 
  (depending on relative sizes of the integral types in the machine)
- When operands have the different signness they are converted to the unsigned type (if it's larger)
- When operands have the different signness conversion is machine-dependent if the signed type is larger 

Overloaded Operators

Lvalues and Rvalues
- Vocab inherited from C
  lvalue = left value
         - yields an object or function
         - Some lvalues, e.g. const's, cannot be on the left-hand T_T
         - Expressions yield object but return them as rvalues, not lvalues T_T 
         - Exception ch13.6, you can use an lvalue when rvalue is required >_>
        
  rvalue = right value
         - When you use an object as an rvalue, you use the object's value (contents)
         - When you use an object as an lvalue, you use the object's identity (address in memory) 

- Operators may require an lvalue or rvalue operands and return lvalues or rvalues.

See table pg. 166

4.11.3 Explicit conversions

!!!! Casts are inherently dangerous. Avoid them !!!!

Vocab
- static_cast
  - "cast away the const" = compiler will no longer stop you from writting to that object
                          - only a 'const_cast' can be used to to this
- const_cast
- reinterpret_cast
  - machine-dependent



 
