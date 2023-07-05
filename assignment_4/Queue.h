//
// Created by kimiho on 4/16/23.
//

#ifndef ASSIGNMENT_4_QUEUE_H
#define ASSIGNMENT_4_QUEUE_H

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node * next;
};

class Queue {
private :
    Node * qfront ;
    Node * qrear ;
public :
    Queue();

    void enqueue ( int value );
    void dequeue ();


    int size () ;
    void displayQueue () ;

    int front () ;
    int back () ;
    bool isEmpty () ;
};
#endif //ASSIGNMENT_4_QUEUE_H
