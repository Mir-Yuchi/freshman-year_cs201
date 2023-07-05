//
// Created by miraz on 28-Mar-23.
//

#ifndef LINKEDLIST_LINKEDLIST_HPP
#define LINKEDLIST_LINKEDLIST_HPP
#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node();
    Node(int);
    Node(int, Node*);
};

class List{
private:
    Node *head;
public:
    List();

    Node* insert_front(int value);
    Node* insert_back(int value);
    Node* insert_afterMiddle(int value);
    Node* insert_after(int index, int value);
    Node* removeNthFromEnd(int n);
    Node* erase_front();
    Node* erase_back();
    Node* erase_middle();
    Node* erase_after(int index);
    Node* reverse_list(Node* head);

    int searchIndexByValue(int value);
    int searchValueByIndex(int index);

    void displayList();

};

#endif //LINKEDLIST_LINKEDLIST_HPP
