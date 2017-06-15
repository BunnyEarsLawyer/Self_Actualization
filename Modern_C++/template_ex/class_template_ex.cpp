
// sauce: https://www.tutorialspoint.com/cplusplus/cpp_templates.htm 
// to compile: $g++ blah.cpp 
#include <iostream>
#include <string>

//
// A Template Class calculator that works with int, double 
//
// The typename and class keywords can be used interchangeably
// E.g. template <typename blah> class calc
// sauce: http://pages.cs.wisc.edu/~driscoll/typename.html
// 
//Template class 
template <class A_Type> class calc
{

  public:

    A_Type multiply(A_Type x, A_Type y);

    A_Type add(A_Type x, A_Type y);

};

// Template functions
template <class A_Type> A_Type calc<A_Type>::multiply(A_Type x,A_Type y)
{

  return x*y;

}

template <class A_Type> A_Type calc<A_Type>::add(A_Type x, A_Type y)
{

  return x+y;

}

//
// What happens when you use the Template Class
//
int main () 
{

   //
   // Inputting int 
   // 
   int i = 3;

   int j = 2;

   calc <int> a_calc_class;

   std::cout << "a_calc_class.add(i, j): " << a_calc_class.add(i, j) << std::endl; 

   //
   // Inputting int 
   // 
   double ii = 3;

   double jj = 2;

   calc <double> b_calc_class;

   std::cout << "a_calc_class.add(ii, jj): " << a_calc_class.add(ii, jj) << std::endl; 

   return 0;

}
