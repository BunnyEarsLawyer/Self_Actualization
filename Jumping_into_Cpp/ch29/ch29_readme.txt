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

-------------------------------- 
How to modify a class to be a template:

1. Declare that there was a template type called Type:

template <typename Type>

2. Add this template declaraction before the class & each function definition

template <typename Type> class Calc

template <typename Type> int Calc::multiply(int x, int y)

3. Also, modify each function definition to indicate that it was part of a template class.

template <typename Type> int Calc<Type>::multiply (int x, int y)

4. Finally, replace 'int' everwhere with 'Type':

template <typename Type> Type Calc<Type>::multiply (Type x, Type y)

:-) Over time you will be comfortable enough to write template classes from scratch
without intermediate code.

IMPORTANT CAVEAT:
Be careful that you don't over-generalize.
E.g. a loop counter that was also an integer, you don't want to change this type.

-------------------------------- 

Templates and header files

So far we've written .cpp files.

What if we want .hh files?

The problem is that code that uses a template function (or template class)
MUST have access to the entire template definition for each function call 
to a template function.
 

- Different from normal functions which require that the caller only know the function
definition.

- You MUST have everything in a .hh file! 

E.g. you have to have the full definition of the constructor and the add method into the 
header file rather than placing them in a .cpp file.

Why? B/c of the way templates are compiled.

- Compiler mostly ignores templates when it first parses them.

- It is only when you use the template with specific concrete type (e.g. Calc<int>)
  that the compiler will generate code.

- Result: You must inclode all of the template code in evrey file that uses the template.

- Alert!!! You might not learn about syntax errors in the template until someone tries to use the template for the first time. 

- When you make a template class, put all template definitions in the header file.

- Tip: use  a different extension than .h. E.g. use .hxx


Summarizing templates:

- Templates allow you to make generic code.

- Templates are used frequently to implement C++ libraries (e.g. Standard Template Library)

- You will often find that you do not need to write template code.

- Be on lookout for code that has the same structure but has different types.

- E.g. code that loops over multiple different vectors and that the operation is the same.

- Many times, you need for a template comes from working on another type 
  that is already a template! 

- E.g. One function adds the values of a vector and another appends all strings in a vector.

  Both use the same logic: iterate and use the + opeartor but they don't work on diff types.

  Follow the principle: "Don't repeat yourself"

Diagnosis template error messages:

- Downside of using templats is that compilers give hard to understand error messages.

- Even if it isn't your templates, e.g. you use the STL library.

Example:

  vector <int, int> vec;   // Creates pages of error.

- What you really want is this:

error: 'int' is not a class, struct, or union type

- The reason it fails is that int doesn't have a val. So you can't do int.val

- However, the compiler just uses 'Duck Typing' for all the things int does not have.
  My interpration, it checks for the behaviors and contents and lists all of the 
  things it didn't like in int.

Another example:
-------------------------
template <typename T>
class Foo
{
   Foo ()
   {
      T x;         // T can't be an integer b/c
      x.val = 1;   // T must have a field called val. Integers have no fields!
   }

}
-------------------------
// This would fail to compile:
Foo <int> a;
-------------------------

- Duck Typing = 
  The template does not care about the type given
  it only cares that the type "fit" into the code.

- In the prev examples, the vector template has a similar constraint on the 2nd parameter.

- All it needs is a type that supports more functionality than a basic integer.

- All of the errors come from the many different ways in which an int would be 
  and invalid type for that template parameter!

 
How to fix a massive wall of text: 

- 1. Start at the 'error' keywords, fix one thing at a time.

E.g. : In instantiation of 'std::_Vector_base<int, int>

Vocab:

- " In instantiation of blah template" = 
  " When trying to compile a template with this set of template parameters"
  = There is a problem when trying to create a template with those params
- _Vector_base is a helper class used to implement vector.
 
E.g. : 159: instantiated from 'std::vector<int, int>'
     template_err.cc:6

- The _Vector_base template failed to compile b/c of an attempt to create the template
  vector<int,int>

- See line 6 of template_err.cc, that's what cause the error.

- Often you can tell what is wrong just looking at your code.

- If you can't tell whats wrong at first and keep reading you get to the actual error message.

E.g. :'int' is not a class, struct or union type

- This tells you the compiler was expecting a class or a struct rather than a built-in type, like int.

- Vectors should be able to hold any type, so this suggests there is a problem with a parameter.

- Double check how to use a vector, then you see you only need a single parameter.

Fix. Recompile.
  
   vector <int> vec;

With templates, the first error often causes all other errors. 

It is better to fix one issue at a time.














