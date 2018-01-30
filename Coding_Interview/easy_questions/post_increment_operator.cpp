#include <iostream>
using namespace std;

// What will the following code output?

int main()
{

    int j = 0;
    for(int i=0; i<100; i++){
        j = j++;
    }

    cout << "j = j++; returns... " << j << endl;

    // Why? b/c  j = j++; is...
    // temp = j;
    // j = j + 1;
    // j = temp;
}
