

#include<iostream>
#include<string>
#include<cstdlib>

#ifndef HASH_H
#define HASH_H


#define tableSize 10

class Node{
public:
    std::string name;
    int animeRating{};
    Node *next{};
    Node(std::string name):name(name){};
    Node(std::string name,int rating):name(name),animeRating(rating){};
};


class hashTable
{
public:
    Node *table[tableSize]{};
    hashTable(int size);
    unsigned int hash(std::string key);
    void printTable();
    void printTableSize();
    bool insert(Node *node);
    Node* deleteNode(std::string val);
    Node* lookup(std::string val);
};

#endif