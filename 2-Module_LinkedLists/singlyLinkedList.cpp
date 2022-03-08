#include"singlyLinkedList.h"

//methods i want
    //insert node after a specific data --wip
    //append -- done
    //prepend (no need to check for duplicates) -- done
    //search for a specific data -- done
    //delete a node by giving a data value -- done
    //print linked list --done

void singlyLinkedList::search(int dataToFind){
    Node *ptr = head;
    if(ptr == NULL){
        std::cout<<"List is empty!!!\n";
    }
    while(ptr != NULL ){
        if(dataToFind == ptr->data){
            std::cout<<"Data "<<dataToFind<<" is present in the list.";
            goto endFunc;
            }
        ptr = ptr->next;
    }
    std::cout<<"Data "<<dataToFind<<" is not present in the list.";
    endFunc:
        std::cout<<"\n";
}

Node* singlyLinkedList::nodeCheck(int dataToFind){
    Node *ptr = head;
    while(ptr != NULL ){
        if(dataToFind == ptr->data){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void singlyLinkedList::appendNode(Node *nodeToAppend){
    if(nodeCheck(nodeToAppend->data)==NULL){
        if(head == NULL){
            head = nodeToAppend;
            std::cout<<"Node Appended\n";
        }
        else{
            Node *ptr=head;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = nodeToAppend;
            std::cout<<"Node Appended\n";
        }
    }
    else{
        std::cout<<"Node is already presnt in the list: "<<nodeToAppend->data<<" Try to append with another data value\n";
    }
}

void singlyLinkedList::printList(){
    if(head == NULL){
        std::cout<<"List is empty.Nothin to print in it\n";
    }
    Node *ptr=head;
    while(ptr!=NULL){
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
}

void singlyLinkedList::prependNode(Node *nodeToPrepend){
    if(nodeCheck(nodeToPrepend->data)==NULL){
        if(head == NULL){
            head = nodeToPrepend;
            std::cout<<"Node Prepended\n";
        }
        else{
            nodeToPrepend->next = head;
            head = nodeToPrepend;
            std::cout<<"Node Prepended\n";
        }
    }
    else{
        std::cout<<"Node is already presnt in the list: "<<nodeToPrepend->data<<" Try to prepend with another data value\n";
    }
}

void singlyLinkedList::insertNode(Node *nodeToInsert,int index){
    if(index <= 0){
        std::cout<<"Cannot insert the node in the specified index cause the index given is less than zero.So prepended the given data\n";
        prependNode(nodeToInsert);
    }
    else if(lengthOfList()<index){
        std::cout<<"Cannot insert the node in the specified index cause the index given is greater than the length of the list.So appended the given data\n";
        appendNode(nodeToInsert);
    }
    else{
        Node *ptr = head;
        while(index>1){
            ptr = ptr->next;
            index--;
        }
        nodeToInsert->next = ptr->next;
        ptr->next = nodeToInsert;
        std::cout<<"Node Inserted at the index specified\n";
    }
}

int singlyLinkedList::lengthOfList(){
    int count=0;
    Node *ptr = head;
        while(ptr!=NULL){
            count++;
            ptr = ptr->next;
        }
    return count;
}

void singlyLinkedList::deleteNode(int dataToDelete){
    if(nodeCheck(dataToDelete)==NULL){
        std::cout<<"No such node is present,cannot delete it: "<<dataToDelete<<"\n";
    }
    else if(lengthOfList()==1){
        if(head->data == dataToDelete){
            head =NULL;
            std::cout<<"The Node has been deleted from the list: "<<dataToDelete<<"\n";
        }
        else{
            std::cout<<"Cannot delete the node specified \n";
        }
    }
    else{
        Node *ptr = head;
        while(ptr!=NULL){
            if(ptr->data == dataToDelete){
                ptr->data = ptr->next->data;
                ptr->next = ptr->next->next;
                break;
            }
            ptr = ptr->next;
        }
        std::cout<<"The Node has been deleted from the list: "<<dataToDelete<<"\n";
    }
}

    //future additions
    //merge two lists
    //split list and give ptr's for both heads

