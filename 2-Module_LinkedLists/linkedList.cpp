#include<iostream>
//methods i want 
        //insert node after a specific data --wip
        //append -- done
        //prepend (no need to check for duplicates) -- done
        //search for a specific data -- done
        //delete a node by giving a data value -- done
        //print linked list --done
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

        void search(int dataToFind){
            
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

        Node* nodeCheck(int dataToFind){
            Node *ptr = head;
            while(ptr != NULL ){
                if(dataToFind == ptr->data){
                    return ptr;
                }
                ptr = ptr->next;
            }
            return NULL;
        }

        void appendNode(Node *nodeToAppend){
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
        
        void printList(){
            Node *ptr=head;
            while(ptr!=NULL){
                std::cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            std::cout<<std::endl;
        }
     
        void prependNode(Node *nodeToPrepend){
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

        void insertNode(Node *nodeToInsert,int index){
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
        
        int lengthOfList(){
            int count=0;
            Node *ptr = head;
             while(ptr!=NULL){
                    count++;
                    ptr = ptr->next;
                }
            return count;
        }

        void deleteNode(int dataToDelete){
            if(nodeCheck(dataToDelete)==NULL){
                std::cout<<"No such node is present,cannot delete it: "<<dataToDelete<<"\n";
            }
            else{
                Node *ptr = head;
                while(ptr!=NULL){
                    if(ptr->next->data == dataToDelete){
                        Node *temp = ptr->next;
                        ptr->next = ptr->next->next;
                        delete temp;
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
};

int main(int argc, char const *argv[])
{
    system("cls");
    std::cout<<"Linked List Implementation\n";
        std::cout<<"1.Append Node\n2.Prepend Node\n3.Delete Node\n4.Insert Node\n5.Print List\n6.Get List Length\n7.Search for an Element\n8.Clear Screen and print options again\n0.To Quit\n";
    int option=0;
    singlyLinkedList list;
    do
    {
        std::cout<<"Enter a option: ";
        std::cin>>option;
        int data;
        switch (option)
        {
            case 0:
                system("cls");
                std::cout<<"Quitting LinkedList Implementation..\n";
                break;        
            case 1:
                std::cout<<"Enter a number to append: ";
                std::cin>>data;
                list.appendNode(new Node(data));
                break;
            case 2:
                std::cout<<"Enter a number to prepend: ";
                std::cin>>data;
                list.prependNode(new Node(data));
                break;
            case 3:
                list.printList();
                std::cout<<"Enter a number to delete it from list: ";
                std::cin>>data;
                list.deleteNode(data);
                list.printList();
                break;
            case 4:
                list.printList();
                int pos;
                std::cout<<"Enter a number to insert into the list: ";
                std::cin>>data;
                std::cout<<"Enter the position of the insertion: ";
                std::cin>>pos;
                list.insertNode(new Node(data),pos);
                list.printList();
                break;
            case 5:
                list.printList();
                break;
            case 6:
                std::cout<<list.lengthOfList()<<std::endl;
                break;
            case 7:
                std::cout<<"Enter a number to be searched in the list: ";
                std::cin>>data;
                list.search(data);
                break;
            case 8:
                system("cls");
                std::cout<<"Linked List Implementation\n";
                std::cout<<"1.Append Node\n2.Prepend Node\n3.Delete Node\n4.Insert Node\n5.Print List\n6.Get List Length\n7.Search for an Element\n8.Clear Screen and print options again\n0.To Quit\n";
                break;
            default:
                std::cout<<"Enter a proper option\n";
                break;
        }
    } while (option != 0);
    return 0;
}
