Templates

Sometimes you want: generic code.

- It won't matter what you are writting because the logic is the same for
ALL TYPES.

- You have already seen this in the STLs (See pg 317)

- STL is a collection of data structures and also algorithms that operate in a generic
fashion.
   - They can hold any type you want.
   - When you store items in an STL vector you tell the vector the type of data it will store.
   - You don't have to work with pre-defined possibilities.

- How did they do it? with Templates.

Vocab:
- Templates
- Instantiate

- Templates allow you to write a function or class without writting in all of the types.
- The compiler can create, or instantiate, a version of the template with all the types filled in.
- E.g. vector<int>
  - The compiler will fill the vector with the type int.

- Using templates is straightfoward.

How to write your own template:
-------------------------------------------------
E.g.

int triangleArea (int base, int height)
{

    return base * height * 0.5;

}

double triangleArea (double base, double height)
{

    return base * height * 0.5;

}

-------------------------------------------------
E.g. 

template < typename T >           // template & typename keywords 
T triangleArea ( T base, T height)    // template parameters in angle brackets
{                                 //

    return base * height * 0.5; 

}

-------------------------------------------------
// Everywhere where T appears in the code will be replaced with double.
triangleArea<double>( 0.5, 0.5)

- It's as thought it was written as:
triangleAreaDouble

- The code we wrote was literally a template that the compiler used to create 
the specific specialized function that handled the double type.

This line:
template < typename T >

" the function (or class) that follows is a template; inside it, I will use the letter T 
as a type (like int, or char) or the name of a specific class. 

When someone needs to use the template, a specific type must be provided for T.

This is done by putting the type inside the angle brackets(<>) before the anem of the 
function or class" 

-------------------------------------------------
Vocab:
-Type inference

Sometimes, the copiler can infer the values for the template parameters

E.g. triangleArea(0.5, 0.5)

Compiler figures out what T is supposed to be.

- Type inference works any time a template parameter is used as the type for one of the function arguments.

-------------------------------------------------
Vocab
- Duck typing "If it talks like a duck, walks like one, it is a duck"

- What if you pass in three vectors to triangleArea? The idea of mutiplying vectors is absurd!


BAD CODE:
vector<int> a,b,c;
triangleArea(a,b,c);

COMPILER COMPLAINS:
template_compile.cc: 
error: no match for 'operator*' in 'base*height'
// It means it couldn't figure out how to multiply bse and height 
// b/c there is no operator * defined for both vectors.
// In other words, vector does not act like a number.
// It "does not act like a number, look like one, nor talk like one"
// Compiler does not care about anything except that the type supports the specific methods
// and operations.

- Duck typing is different from poly morphic functions b/c...

- a polymorphic function takes a pointer to an interface class and can only call methods
  defined on that interface class.
- With templates there is no pre-defined interface.

-------------------------------------------------
Template Classes

- Usually they are the purview of library writers.
- They want to make classes like 'vector' and 'map'

- You will probably write more template functions than classes
but it is benefitial to know how to use them.

Vocab
- Wrapping = when one function calls another function to
implement most of the functionality but the outer function also does some small amount of additional work. E.g. logging and error checking.

E.g. small class to wrap an array:

template <typename T> class ArrayWrapper
{

private:
    T * _p_mem;

}

 - Just like in the function, use the 
   'template' keyword we declare we are going to make a template
   then add the list of template parameters.

Example: Adding a constructor for the ArrayWrapper template.

----------------------------------
template <typename T> class ArrayWrapper
{
public:
    ArrayWrapper(int size);

private:
    T * _p_mem;

}

// now, to define the constructor outside of the class, we
// need to start off by marking the function as being a template

template <typename T>
ArrayWrapper<T>::ArrayWrapper (int size)
    : _p_mem( new T[ size] )
{
}
----------------------------------

Tips for working with templates:
- Write your class normally first, them make it into a template.

See calc.cpp




