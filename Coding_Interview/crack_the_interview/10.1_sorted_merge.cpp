
#include<iostream>
#include<list>
#include<array>  // Modern std::array

// Correct answer:
// A larger than B
/*
void sorted_merge_answer(int[] A, int[] B, int lastA, int lastB)
{

   // Indeces of the last elements in each array
   int idxA = lastA - 1;
   int idxB = lastB - 1;
   int idxmerged = lastB + lastA -1; // end of merged array
   while(idxB >=0) {
       if(idxA >=0 && A[idxA] > B[idxB]) {
           A[idxmerged] = A[idxA];
           idxA--;
       }
       else{
           A[idxmerged] = A[idxB];
           idxB--;
       }
       idxmerged--;
   }
*/
void sorted_merger(const std::array<int, 5> & A , const std::array<int, 3> & B, int nA, int nB)
{
/*
   int nR = nA;

   int i, j = 0;

   int R[nR];

   for(int k = 0; k < nR; k++) {

       while(j < nB){
           if(A[i] < B[j]) {
               R[k] = A[i]; i++;
           } 
           else{
               R[k] = B[j]; j++;
           } 
       } 
    }      

   // Print resulting array
   for(int k = 0; k < nR; k++) {
       std::cout << " k " << k  << "R[k] = " << R[k] << std::endl;

   }
*/
}

int main()
{

int nA = 5;
int nB = 3;

// C-style arrays
int large_array [] = {1,8,0,0,0};
int small_array [] = {2,3,5};
// C-style arrays decay to pointers
const int * p_to_large_array = large_array;

//
// Always prefer modern std::array to a built-in array!
// See pg. 17 of Effective Modern C++ book
//
std::array<int, 5> A;
A = {1,8,0,0,0};
std::array<int, 3> B;
B = {2,3,5};

sorted_merger(A, B, nA, nB);

std::cout << "hi" << std::endl;
return 0;
}
