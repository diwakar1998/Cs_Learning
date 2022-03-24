#include<iostream>
#include"stack.h"
int main(int argc, char const *argv[])
{
    stack mystack;
    mystack.Push("diwakar",23);
    mystack.Push("chemb",99);
    mystack.Push("boochi",9999);
    mystack.Push("baratsarat",6969);
    mystack.PrintStack();
    mystack.Pop();
    mystack.Pop();
    mystack.Pop();
    mystack.Pop();
    mystack.Pop();

    std::cout<<"\n\nNew Stack\n\n";
    mystack.Push("Laptops",2);
    mystack.Push("iPad",1);
    mystack.Push("1+ 7T",1);
    mystack.PrintStack();
}
