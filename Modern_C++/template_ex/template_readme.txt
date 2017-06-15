Templates


- Templates enable you to define a family of functions or classes that can
operate with different types of information.

- Templates are 'type-safe' b/c their parameters are known at compile time.

- Put declaration and implementation on the same file (.h)
because they are instantiated at compile time (IMPORTANT)

- If you need the template code to be usable by other units (.cpp files), put it in the .h file

- Cons: longer build time, code blote, it can be difficult to debug code that is developed using templates.

- Debug difficulty b/c the compiler replaces the teampltes, it's hard for the debugger to locate the code at runtime.

- No information hiding. All code exposed in the header file.

- STL itself is a collection of template classes, but they are not used to write conventional libraries.

- Prefer a template over derived classes when run-time efficiency is at premium.


- You can seaparte templates into .h and .cpp using export...but it's controversial 
