#include<iostream>
#include<cstdio>
/*
LinkedList Implementation
1.able to create a linked list
2.search through the list
3.insert a new node in list
4.delete a single element in list
5.delete entire linked list
*/
class node {
   public:
   int value;
   node *nextLink;

   node() : value(0){}
   node(int a):value(a) ,nextLink(nullptr){}
};

void  insertNode(node* currentHead,int value){
   node temp(value);
   currentHead->nextLink=&temp;
   temp.nextLink=nullptr;
   currentHead = &temp;
}

int main(int argc, char const *argv[]) {
   //end of day 1 able to make a insertion method
   node head(2);
   insertNode(&head,5);
   std::cout<<head.nextLink->value<<std::endl;
//   printf("%p",head.nextLink);  
   printf("%p",head.nextLink->nextLink);
   return 0;
}