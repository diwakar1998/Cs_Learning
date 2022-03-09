#include<iostream>
#include<cstdio>
#include<vector>

class Node{
public:
    int index;
    const char* data;
    Node *next;
    //    ,
    Node(int indexPassed,const char* dataPassed):index(indexPassed),data(dataPassed),next(nullptr){}
};

class BrowserHistory{
public:
    Node *head;
    int current=1;
    BrowserHistory(const char* parameter){
        head = new Node(current,parameter);
    }
    void visit(const char* urlToVisit);
    void printList();
    int listLength();
    Node *returnNode_Index(int index);
    const char* back(int steps);
    const char* forward(int steps);
};

void BrowserHistory::printList(){
    Node* temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int BrowserHistory::listLength(){
    Node* temp = head;
    int count=0;
    do{
        count++;
        temp = temp->next;
    }while(temp != nullptr);

    return ++count;
}

void BrowserHistory::visit(const char* urlToVisit){
    //append after the current node
    current++;
    Node *urlPtr = new Node{current,urlToVisit};
    if(head == nullptr){
        head = urlPtr;
        return;
    }
    else{
        Node *temp = returnNode_Index(current-1);
        temp->next = urlPtr;
        urlPtr->next = nullptr;
    }
}

const char* BrowserHistory::back(int steps) {
    if(current-steps <=1){
        current = 1;
        return head->data;
    }
    else{
        Node *temp = returnNode_Index(current-steps);
        current = temp->index;
//        temp->next = nullptr;
        return temp->data;
    }
}

const char* BrowserHistory::forward(int steps) {
    if(current+steps > listLength()){
        return "Cannot move any steps further\n";
    }
    else{
        Node *temp = returnNode_Index(current+steps);
        current = temp->index;
        return temp->data;
    }
}

Node *BrowserHistory::returnNode_Index(int index) {
    Node* temp = head;
    if(index>1 && index<=listLength()){
        while(temp){
            if(index == temp->index){
                break;
            }
            temp=temp->next;
        }
    }
    return temp;
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
