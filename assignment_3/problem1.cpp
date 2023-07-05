#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(){ value=0; next= nullptr;}
    Node(int x) { value=x; next= nullptr;}
    Node(int x, Node *n) { value=x; next=n;}
};

class List{
private:
    Node* head;
public:
    List() {head = nullptr;}

    Node* insert_front(int x){
        Node *newNode = new Node;
        newNode->value=x;
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node* insert_back(int x){
        Node *h=head;
        Node *newNode = new Node;
        newNode->value=x;

        if( !head ) { head=newNode; return newNode; }
        while( h->next!=nullptr ) { h=h->next; }
        h->next=newNode;
        return head;
    }

    Node* insert_afterMiddle(int x){
        Node *h=head;
        Node *newNode = new Node();
        newNode->value=x;
        int size=0;

        while(h){size++; h=h->next;}
        h=head;
        for(int i=0; i<size/2; ++i) {h=h->next;}
        newNode->next=h->next;
        h->next=newNode;
        return head;
    }
    Node* insert_after(int index, int x){
        Node *h=head;
        Node *newNode = new Node();
        newNode->value=x;

        for(int i=0; i<index; ++i) {h=h->next;}
        newNode->next=h->next;
        h->next=newNode;
        return head;
    }

    Node* erase_front(){
        Node *h=head;
        head=head->next;
        delete h;
        return head;
    }
    Node* erase_back(){
        Node *h=head;
        while (h->next->next!= nullptr){h=h->next;}
        delete h->next;
        h->next= nullptr;
        return head;
    }
    Node* erase_middle(){
        Node *h=head;
        int size=0;

        while(h){size++; h=h->next;}
        h=head;
        for(int i=0; i<size/2-1; ++i) {h=h->next;}
        Node *temp =h->next;
        h->next=h->next->next;
        delete temp;
        return head;
    }
    Node* erase_after(int index){
        Node *h = head;

        for(int i=0; i<index; ++i) {h=h->next;}
        Node *temp =h->next;
        h->next=h->next->next;
        delete temp;
        return head;
    }

    int searchIndexByValue(int val) {
        Node *h = head;
        int index = 0;
        while (h != nullptr) {
            if (h->value == val) return index;
            index++;
            h = h->next;
        }
        return -1;
    }
    int searchValueByIndex(int index){
        Node *h = head;
        int count=0;
        while(h!=nullptr){
            if(count==index) return h->value;
            count++;
            h=h->next;
        }
        return -1;
    }

    void displayList() {
        if (!head) return;
        Node *current_node = head;

        while (current_node) {
                cout << current_node->value << " ";
            current_node = current_node->next;
        }
    }
};
int main(int argc, const char * argv[]) {
    List l;

    //test insert_front()
    for(int i=1;i<6;i++){
        l.insert_front(i);
    }
    cout<<"Test insert_front(): ";
    l.displayList();
    cout<<endl;

    //test insert_afterMiddle()
    l.insert_afterMiddle(100);
    cout<<"Test insert_afterMiddle(100): ";
    l.displayList();
    cout<<endl;

    //test insert_back()
    for(int i=6;i<11;i++){
        l.insert_back(i);
    }
    cout<<"Test insert_back(): ";
    l.displayList();
    cout<<endl;

    //test erase_middle()
    l.erase_middle();
    cout<<"Test erase_middle(): ";
    l.displayList();
    cout<<endl;

    //test erase_back()
    l.erase_back();
    cout<<"Test erase_back(): ";
    l.displayList();
    cout<<endl;

    //test insert_after()
    l.insert_after(4, 999);
    cout<<"Test insert_after(4,999): ";
    l.displayList();
    cout<<endl;

    //test erase_after()
    l.erase_after(4);
    cout<<"Test erase_after(4): ";
    l.displayList();
    cout<<endl;

    //test erase_front()
    l.erase_front();
    cout<<"Test erase_front(): ";
    l.displayList();
    cout<<endl;

    //test searchValueByIndex()
    cout<<"Test searchValueByIndex(3): "<<l.searchValueByIndex(3)<<endl;

    //test searchIndexByValue()
    cout<<"Test searchValueByIndex(3): "<<l.searchIndexByValue(3)<<endl;
    return 0;
}