#include<iostream>
#include<vector>


int main()
{
    // C++11 allowed:
    // std::vector<int> my_array = {-2,3,2,-1};
    std::vector<int> my_array = {-1,1,3,2,-1};
    std::vector<int>::iterator it = my_array.begin();
  
    int global_max_sum = *it; 
    int current_max_sum = *it; 
    
    for(it = my_array.begin() + 1; it != my_array.end(); it++) {

        int tmp_sum = *it + current_max_sum;
        if(tmp_sum > *it ){ current_max_sum = tmp_sum; }
        else{ current_max_sum = *it; }

        std::cout << *it << " " << current_max_sum << std::endl;

        if(current_max_sum > global_max_sum) { global_max_sum = current_max_sum; }
    }

    std::cout << "the max sum: " << global_max_sum;

    return 0;
}
