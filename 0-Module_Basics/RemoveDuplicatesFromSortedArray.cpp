#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    /* code */
    int nums[] = {-2,-2,-1,0,1,2,2,3,5};
    size_t numsSize = sizeof(nums)/sizeof(int);
    
    //O(N)-->approach
    //O(N)->space try for O(1)
    // std::vector<int> ans;
    // for (int i = 0; i < numsSize; i++)
    // {
    //     int current = nums[i];
    //     int next = nums[i+1];

    //     if(current == next){
    //         continue;
    //     }
    //     ans.push_back(current);
    // }
    // for(auto var : ans)
    // {
    //     std::cout<<var<<std::endl;
    // }


    //O(N)->Time
    //O(1)->Space
    int count=0;
    for (size_t i = 0; i < numsSize; i++)
    {   
        if(nums[i]==nums[i+1]){
            
            for (int j = i+1; j < numsSize-1; j++)
            {
                nums[j] = nums[j+1];
                nums[j+1]=0;
            }
    //copy the new nums to current nums
            numsSize--;
            count++;
        }

    }
    //std::cout<<count<<std::endl;
    for (size_t i = 0; i < numsSize; i++)
    {
        std::cout<<nums[i]<<std::endl;
    }
    
    
        
    return 0;
}
