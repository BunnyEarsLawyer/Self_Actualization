#include<iostream>
using namespace std;

int main()
{
    int rr = 3;
    int cc = 3;
    int matrix_nn [rr][cc];
    int rot_nn [rr][cc];
    int counter = 0;
    // O(n^2)
    for (int ii = 0; ii < rr; ++ii) {
        for (int jj = 0; jj < cc; ++jj) {
            matrix_nn[ii][jj] = counter;
            counter++;
            cout << matrix_nn[ii][jj] << endl;
        }
    } 
    int rot_ii = 0;
    for (int ii = 0; ii < rr; ++ii) {
        for (int jj = 0; jj < cc; ++jj) {
            rot_ii = rr - ii - 1;
            rot_nn[ii][jj] = matrix_nn[jj][rot_ii];
            cout << rot_nn[ii][jj] << endl;
        }
    } 
    cout << "hi" << endl;
 
}
