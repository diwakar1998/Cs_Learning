#include<iostream>

int main(int argc, char const *argv[])
    
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b,numberoftests;
    std::cin>>numberoftests;
    for(int i=0;i<numberoftests;i++){
        std::cin>>a>>b;
        std::cout<<a+b<<std::endl;
    }

    return 0;
}
