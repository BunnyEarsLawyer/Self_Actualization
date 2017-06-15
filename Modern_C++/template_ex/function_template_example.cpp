
// sauce: https://www.tutorialspoint.com/cplusplus/cpp_templates.htm 
// to compile: $g++ blah.cpp 
#include <iostream>
#include <string>

using namespace std;

//
// Family of functions A.K.A function template
//
template <typename T>
inline T const& Max (T const& a, T const& b)  
{ 
   return a < b ? b:a; 
} 

int main () {
   //
   // Inputting int to Max function 
   // 
   int i = 39;
   int j = 20;
   cout << "Max(i, j): " << Max(i, j) << endl; 

   //
   // Inputting double to Max function 
   // 
   double f1 = 13.5; 
   double f2 = 20.7; 
   cout << "Max(f1, f2): " << Max(f1, f2) << endl; 

   //
   // Inputting strings to Max function 
   // 
   string s1 = "Hello"; 
   string s2 = "World"; 
   cout << "Max(s1, s2): " << Max(s1, s2) << endl; 

   return 0;
}
