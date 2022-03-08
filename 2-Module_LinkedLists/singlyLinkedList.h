#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H
#include<iostream>

class Node{
    public:
        int data;
        Node *next;
        Node():data(0),next(NULL){}
        Node(int dataPassed):data(dataPassed),next(NULL){}
};

class singlyLinkedList{
    public:
        Node *head;
        singlyLinkedList():head(NULL){}
        singlyLinkedList(Node *nodePassed):head(nodePassed){}
        void search(int dataToFind);
        Node*nodeCheck(int dataToFind);
        void appendNode(Node *nodeToAppend);
        void printList();
        void prependNode(Node *nodeToPrepend);
        void insertNode(Node *nodeToInsert,int index);
        int lengthOfList();
        void deleteNode(int dataToDelete);
};
#endif