#include <iostream>
#include <vector>
#include<assert.h>
int removeDuplicates(std::vector<int>& nums) {
    //O(n) time complexity;O(1) space complexity
    int i;
    if(nums.size() == 0){
        return 0;
    }
        i=0;
        for(size_t j=1;j<nums.size();j++)
        {  
                if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
                }
            }
    return i+1;
    }
        

int main(int argc, char const *argv[])
{
    
    std::vector<int> nums = {1,1,1};
    
    int k = removeDuplicates(nums); // Calls your implementation

    for (int i = 0; i < k; i++) {
        std::cout<<nums[i]<<" ";
    }
    return 0;
}
