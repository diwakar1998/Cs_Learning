#include<iostream>
#include"singlyLinkedList.h"

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
