//
// Created by miraz on 28-Mar-23.
//

#include "LinkedList.hpp"

Node::Node() { val=0; next=nullptr; }
Node::Node(int value) { val=value; next= nullptr; }
Node::Node(int value, Node *ptr) { val=value; next=ptr; }

List::List() { head= nullptr; }

Node *List::insert_front(int value) {
    Node *newNode = new Node();
    newNode->val=value;
    newNode->next=head;
    head=newNode;
    return newNode;
}

Node *List::insert_back(int value) {
    Node *h = head;
    Node *newNode = new Node();
    newNode->val=value;

    if(!h){head=newNode; return head;}
    while(h->next!= nullptr){ h=h->next;}
    h->next=newNode;
    return newNode;
}
// insert after middle
Node *List::insert_afterMiddle(int value){
    Node *h = head;
    int size=0;
    while(h!= nullptr){h=h->next; size++;}
    h=head;
    for(int i=1; i<size/2+1; ++i){h=h->next;}
    Node *newNode = new Node();
    newNode->val=value;
    newNode->next=h->next;
    h->next=newNode;
    return newNode;
}

Node *List::removeNthFromEnd(int n) {
    if (!head) return NULL;
    Node *h = head;
    int size = 0;
    while (h) { size++, h = h->next; }
    h = head;
    if(size==1) { return NULL; }
    for (int i = size; i > 1; --i) {
        if (i == n+1) break;
        h = h->next;
    }   if(h->next==nullptr) {
        Node *temp=h;
        h=nullptr;
        delete temp;
    }else{
        Node *temp=h->next;
        h->next=h->next->next;
        delete temp;
    }
    return head;
}
Node *List::reverse_list(Node* head) {
    if(!head or !(head->next))  return head;
    Node* reverse= reverse_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reverse;
}
Node *List::insert_after(int index, int value) {
    Node *h=head;
    Node *newNode = new Node();
    newNode->val=value;

    for(int i=0; i<index; ++i) {h=h->next;}
    newNode->next=h->next;
    h->next=newNode;
    return newNode;
}

Node *List::erase_front() {
    Node *h = head;
    head=head->next;
    delete h;
    return head;
}

Node *List::erase_back(){
    Node *h = head;
    while(h->next->next!= nullptr) { h=h->next;}
    delete h->next;
    h->next= nullptr;
    return head;

}
Node *List::erase_middle() {
    Node *h=head;
    int size=0;
    while(h!= nullptr){h=h->next; size++;}
    h=head;
    for(int i=0; i<(size/2)+1; ++i){h=h->next;}
    Node *temp=h->next;
    h->next=h->next->next;
    delete temp;
    return head;
}

Node *List::erase_after(int index) {
    Node *h=head;
    for(int i=1; i<index;++i){h=h->next;}
    Node *temp=h->next;
    h->next=h->next->next;
    delete temp;
    return head;
}

int List::searchIndexByValue(int value) {
    Node *h = head;
    int index=0;
    while(h!=nullptr){
        if(h->val==value) return index;
        index++;
        h=h->next;
    }
    return -1;
}

int List::searchValueByIndex(int index) {
    Node *h = head;
    int count=0;
    while(h!=nullptr){
        if(count==index) return h->val;
        count++;
        h=h->next;
    }
    return -1;
}

void List::displayList() {
    Node *h=head;
    if (!h) { cout<<"List is empty"<<endl; return; }
    while(h!=nullptr){
        cout<<h->val<<" ";
        h=h->next;
    }
}



