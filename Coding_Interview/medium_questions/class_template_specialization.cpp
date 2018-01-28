#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

// Primary template (defined but not initialized)
template <typename T> struct Traits;

// ----------------------------------------------------------
// Define specializations for the Traits class template here:

//
// Template Base 
//
template <typename T>
struct Traits
{

    // Static: This feature means the variable is not automatic, 
    // i.e. allocated and freed on the stack with each invocation 
    // of the function. Instead the variable is allocated in the 
    // static data area, it is initialized to zero and persists 
    // for the life of the program.
    static string name(int n)
    {
	return "unknown";
    }
};

//
// Template Fruit specialization
//
template <>
struct Traits<Fruit>
{
    static string name(int n)
    {
	return n==0?"apple":n==1?"orange":n==2?"pear":"unknown";
    }
};
//
// Template Color specialization
//
template <>
struct Traits<Color>
{
    static string name(int n)
    {
	return n==0?"red":n==1?"green":n==2?"orange":"unknown";
    }
};
// in: enum values for two types 
// out: enum names or 'unknown' if enum value is not valid

// ----------------------------------------------------------
int main()
{
    cout << "Enter how many lines first, then enter 2 numbers on the same line: ";
    int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
