// Without using aliases:
// $g++ -std=c++11 nullptr_vs_NULL.cpp 

#include <iostream>
#include <cstddef>

int main()
{

//
// In C++, NULL is defined as #define NULL 0 (a macro)
//  so it is basically int, that is why f(int) is called. (See source)
//

    int *p_to_NULL;
    
    p_to_NULL = NULL; 

//
// nullptr: Pointer with an address of 0
//

//
// nullptr: a pointer type, it can only be converted to other pointer types
//          Technically, it has type std::nullptr_t and is declared in <cstddef> as:
//
// namespace std
// {
//    typedef decltype(nullptr) nullptr_t;
// }
//
// Source: https://thenewcpp.wordpress.com/2011/11/03/nullptr/
//

    int *p_is_nullptr;

    p_is_nullptr = nullptr;

    std::cout << "p_is_nullptr ... \n " <<  p_is_nullptr << "\n";

}
