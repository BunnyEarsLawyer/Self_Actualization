From C++ standard

http://www.codingstandard.com/rule/3-4-1-do-not-return-a-reference-or-a-pointer-to-an-automatic-variable-defined-within-the-function/

3.4.2 Do not assign the address of a variable to a pointer with a greater lifetime

The C++ Standard defines 4 kinds of storage duration:
                     
        static     | until program termination
        thread     | until thread termination
        automatic  | upon exiting the enclosing block
        dynamic    | NOT FIXED like the previous 3 


3.4.3
 C++ Language Standard provides RAII wrappers for many resources, such as:

        dynamically allocated memory, e.g. std::unique_ptr
        files, e.g. std::ifstream
        mutexes, e.g. std::lock_guard



