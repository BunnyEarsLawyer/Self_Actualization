// C++ 11: R-value reference 
// Used for 2 things:
//    1. Moving semantics
//    2. Perfect Forwarding

#include<iostream>
using namespace std;
//
// You can only overload function with lvalue ref. and rvalue ref.
//
void print_integer(int& i) {cout << "lvalue ref: " << i << endl;}
void print_integer(int&& i) {cout << "rvalue ref: " << i << endl;}
//
// If we have this function
// then print_integer(a) compiler won't know which function to call.
// print_integer(int i) or print_integer(int & i)?
// compiler sees print_integer(6), same thing
// print_integer(int i) or print_integer(int && i)?
//
/* void print_integer(int i) {} */

int main()
{
    int a = 5;  // a is an lvalue
    int& b = a; // b is an lvalue reference 
                // (used to be called reference)

    // int&& c;    // c is an rvalue reference (notice &&) 

    print_integer(a); // calls print_integer(int& i) 

    print_integer(6); // calls print_integer(int&& i) 

}
