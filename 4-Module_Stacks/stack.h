#ifndef STACK_H
#define STACK_H

#include<string>
#include<iostream>
class stack
{
private:
    struct item{
        std::string name;
        int value;
        item* prev;
    };

    item* stackPtr;
public:
    void Push(std::string name,int value);
    void Pop();
    void ReadItem(item* readPtr);
    void PrintStack();

    stack();
    ~stack();
};


#endif