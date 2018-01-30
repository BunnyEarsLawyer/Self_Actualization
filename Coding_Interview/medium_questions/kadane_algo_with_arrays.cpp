#include<iostream>
#include<vector>


int main()
{
    // C++11 allowed:
    int A[5] = {-1,1,3,2,-1};
    int global_max_sum  = A[0]; 
    int current_max_sum = A[0]; 

    for(int i = 1; i < 5; i++){
        std::cout << "idx: " <<  i << " val: " << A[i] << std::endl;

        int tmp_sum = A[i] + current_max_sum;
        if(tmp_sum > A[i] ){ current_max_sum = tmp_sum; }
        else{ current_max_sum = A[i]; }

        std::cout << A[i] << " " << current_max_sum << std::endl;

        if(current_max_sum > global_max_sum) { global_max_sum = current_max_sum; }
    }

    std::cout << "the max sum: " << global_max_sum << std::endl;
     
    return 0;
}
