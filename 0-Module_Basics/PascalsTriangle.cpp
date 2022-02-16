#include<iostream>
#include<vector>

// std::vector<std::vector<int>>
int generate(int numRows) {
        for (int i = 1; i <= numRows; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                std::cout<<j;
            }
            std::cout<<std::endl;
        }
    return 0;     

    }

int main(int argc, char const *argv[])
{
    auto ans = generate(5);

    // for(auto rows : ans)
    // {
    //     for(auto nums : rows)
    //     {
    //         std::cout<<nums<<std::endl;   
    //     }   
    // }
    return 0;
}
