#include"stack.h"

#include <utility>

stack::stack(){
    stackPtr = nullptr;
}

stack::~stack() {
    item* p1;
    item* p2;

    p1 = stackPtr;
    while(p1 != nullptr){
        //copy pointer to head to another item pointer
        p2 = p1;
        //p1 i.e stackptr now points to the item below
        p1 = p1->prev;
        //p2 i.e the previous stackptr is disconnected from chain
        p2->prev = nullptr;
        //deleting(more like deallocating the memory) the previous head of stack
        delete p2;
    }
}

void stack::Push(std::string name, int value) {
    item* newPtr = new item;
    newPtr->name = std::move(name);
    newPtr->value = value;

    if(stackPtr == nullptr){
        stackPtr = newPtr;
        stackPtr->prev = nullptr;
    }
    else{
        newPtr->prev = stackPtr;
        stackPtr = newPtr;
    }

}

void stack::ReadItem(item *readPtr) {
    std::cout<<"-------------\n";
    std::cout<<"name: "<<readPtr->name<<std::endl;
    std::cout<<"name: "<<readPtr->value<<std::endl;
    std::cout<<"-------------\n";
}
void stack::Pop() {
    if(!stackPtr){
        std::cout<<"Nothing is on the stack currently\n";
    }
    else{
        std::cout<<"Popping item\n";
        item* p = stackPtr;
        ReadItem(p);
        stackPtr = stackPtr->prev;
        p->prev = nullptr;
        delete p;
    }
}

void stack::PrintStack() {
    if(stackPtr){
        item *p = stackPtr;
        while(p){
            ReadItem(p);
            p=p->prev;
        }
    }
    else{
        std::cout<<"Stack is empty.Nothing to print.\n";
    }
}