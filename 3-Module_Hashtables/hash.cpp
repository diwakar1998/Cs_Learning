#include"hash.h"



hashTable::hashTable(int size) {

    for(int i{};i<tableSize;i++){
        table[i] = nullptr;
    }
}

void hashTable::printTable() {

    for (int i = 0; i < tableSize; ++i) {
        std::cout<<i<<"=>";
        Node *temp=table[i];
        if(temp == nullptr){
            std::cout<<".....";
        }else {
//            << "=>" << table[i]->animeRating
            while(temp!= nullptr) {
                std::cout << temp->name<<"->";
                temp = temp->next;
            }
//                std::cout << temp->name<<"->";
        }
        std::cout<<"\n";
    }
}
unsigned int hashTable::hash(std::string key) {
    int length = key.size();
    unsigned int hashValue = 0;
    for(int i{};i<length;i++){
        hashValue += key[i];
        hashValue=(hashValue *= key[i])%tableSize;
        hashValue+=key[i]*key[i];
    }
    return hashValue%tableSize;
}

bool hashTable::insert(Node *node) {
    if(node == nullptr) return false;
    int index = hash(node->name);
    node->next = table[index];
    table[index] = node;
    return true;
}

void hashTable::printTableSize() {

    for (int i = 0; i < tableSize; ++i) {
        std::cout<<i<<"=>";
        Node *temp=table[i];
        if(temp == nullptr){
            std::cout<<"0";
        }else {
//            << "=>" << table[i]->animeRating
            int count=0;
            while(temp!= nullptr) {
                count++;
                temp = temp->next;
            }
            std::cout<<count;
        }
        std::cout<<"\n";
    }
}

Node* hashTable::lookup(std::string val) {
    int index = hash(val);
    Node *temp=table[index];
    Node *prev = nullptr;
    if(temp == nullptr){
        std::cout<<"No match found!!\n";
        return nullptr;
    }
    else {
        while(temp!= nullptr & temp->name == val) {
            prev = temp;
            temp = temp->next;
        }
        std::cout<<"Match found! ---> "<<prev->name<<"\n";
        return temp;
    }
}

Node* hashTable::deleteNode(std::string val) {

    //couldnt understand shortcut codes so did my own implementation or say i was lazy ;-)
    int index = hash(val);
    Node *temp=table[index];
    //first node null
    if(temp == nullptr){
        std::cout<<"No value present for the key: "<<index<<"\n";
        return nullptr;
    }
    //first node is match and also other nodes might be present
    if(temp->name==val){
        if(temp->next == nullptr )
            table[index] = nullptr;
        else
            table[index] = table[index]->next;
        return nullptr;
    }
    //handles list case
    Node* prev = nullptr;
    while(temp != nullptr ) {
        if(temp->name == val) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp->next == nullptr){
        prev->next = nullptr;
    }
    else{
        prev->next = temp->next;

    }
    return temp;
}

