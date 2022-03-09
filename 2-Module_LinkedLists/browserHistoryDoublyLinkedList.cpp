#include<iostream>
#include<cstdio>

class Node{
public:
    Node *previous;
    const char* data;
    Node *next;
    Node(const char* dataPassed):previous(nullptr),data(dataPassed),next(nullptr){}
};

class BrowserHistory{
public:
    Node *head;
    Node *current;
    BrowserHistory(const char* parameter){
        head = new Node(parameter);
        current = head;
    }
    void visit(const char* urlToVisit);
    void printList();
    const char* back(int steps);
    const char* forward(int steps);
};

void BrowserHistory::visit(const char *urlToVisit) {
    Node *urlPtr = new Node{urlToVisit};
    if(head == current){
        head->next = urlPtr;
        urlPtr->previous =head;
        urlPtr->next = nullptr;
        current = urlPtr;
        return;
    }
    else{
        urlPtr->previous =current;
        current->next = urlPtr;
        urlPtr->next = nullptr;
        current = urlPtr;
    }
}
const char *BrowserHistory::forward(int steps) {
    Node *temp = current;
    while(steps>0){
        current = current->next;
        if(current == nullptr){
            current = temp;
            return "Cannot go further anymore!\n";
        }
        steps--;
    }
    return current->data;
}
const char *BrowserHistory::back(int steps) {
//    std::cout<<current->data;
    while(steps>0){
        current = current->previous;
        if(current == head){
            return head->data;
        }
        steps--;
    }
    return current->data;
}
void BrowserHistory::printList(){
    Node* temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    BrowserHistory browserHistory{"leetcode.com"};
    browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistory.printList();
    std::cout<<std::endl;
    browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistory.printList();
    std::cout<<std::endl;
    browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    browserHistory.printList();
    std::cout<<std::endl;
    std::cout<<browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    std::cout<<std::endl;
    browserHistory.printList();
    std::cout<<std::endl;
    std::cout<<browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
    std::cout<<std::endl;
    browserHistory.printList();
    std::cout<<std::endl;
    std::cout<<browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    std::cout<<std::endl;
    browserHistory.printList();
    std::cout<<std::endl;
    browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    browserHistory.printList();
    std::cout<<std::endl;
    std::cout<<browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
    std::cout<<std::endl;
    browserHistory.printList();
    std::cout<<std::endl;
    std::cout<<browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    std::cout<<std::endl;
    browserHistory.printList();
    std::cout<<std::endl;
    std::cout<<browserHistory.back(7);                  // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    std::cout<<std::endl;
    return 0;
}
