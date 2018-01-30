
// $clang++ -std=c++11 first_recurring_character.cpp 

#include<iostream>
#include<string>
#include<unordered_set> // c++11

using namespace std;


char find_first_recurring_character(string &input){

    unordered_set<char> my_set;

    for(string::iterator idx = input.begin(); idx < input.end(); idx++){

	cout << "idx: " << *idx << " ";
        cout << endl;

        char current_char = *idx;

        // if a value is not found, set returns the unodered set end()
        if(my_set.find(current_char) == my_set.end()){
            my_set.insert(current_char); 
	}
        else{
	    return *idx; 
        }

    }

    return -1;
}



int main(){

    string input = "abca";

    // May comment this line out:
    cout << "Enter a word: ";
    cin >> input;

    char output;

    output = find_first_recurring_character(input);

    cout << "FOUND THIS: " << output << "\n";
}
