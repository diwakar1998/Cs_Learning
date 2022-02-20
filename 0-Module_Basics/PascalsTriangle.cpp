#include<iostream>
#include<vector>
#include<cstdio>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans = {};
    
    for(int i=0;i<numRows;i++){
        std::vector<int> temp = {};
        for(int j=0;j<=i;j++)            
            if(j==0 || j==i){
                temp.push_back(1);
            }
            else{
                temp.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            ans.push_back(temp);
    }
    std::cout<<std::endl;
    return ans;    
    }

int main(int argc, char const *argv[])
{
    int n = 0;
    int k=1;
    std::cin>>n;
    auto ans = generate(n);
    for(auto rows : ans)
    {
        // int x=n-k;
        // while(x!=0){
        //     printf(" ");
        //     x--;
        // }
        for(auto nums : rows)
        {
            std::cout<<nums<<" ";   
        }   
        std::cout<<std::endl;
        k++;
    }
    return 0;
}
