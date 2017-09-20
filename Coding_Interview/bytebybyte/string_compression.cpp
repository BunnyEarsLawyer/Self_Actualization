// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
using namespace std;



// Sample: 
// Assumptions
// - Only [a-z]
// - No capitalization, only exact same letters
// - No special characters 
// - characters to compress are next to each other

// compression("a")
// compression("aaa")
// compression("aaabbb")
// compression("aaabccc")

// Passing input by reference won't let me pass a constant e.g. func("blah")
string compression( string input )
{

    string result;

    int counter = 0;
    // Because I cannot compare a string to *itt
    char curr_char;
    string combination;

    for(string::iterator it = input.begin(); it != input.end(); ++it )
    {

        curr_char = *it;
        cout << " char *it " << *it << endl;

        for(string::iterator itt = input.begin(); itt != input.end(); ++itt )
        {

            if(curr_char == *itt)
            {    
                counter++; 
                it = itt;
            }

        }

        string number = std::to_string(counter);
        cout << " number: " << counter << endl;

        combination = curr_char + number;
        cout << " combination: " << combination << endl;

        result.append(combination);

        counter = 0;

    }

    cout << " result: " << result << endl;

    if(result.size() > input.size())
    {
        return input;
    }
    else
    {
        return result;
    }

}


int main()
{
    string a = "baaa";
    cout << "result: " << compression(a) << endl;
    cout << "result: " << compression("z") << endl;
    cout << "result: " << compression("aaa") << endl;
    cout << "result: " << compression("aaabbb") << endl;
    cout << "result: " << compression("aaacbbb") << endl;

    return 0;
}
