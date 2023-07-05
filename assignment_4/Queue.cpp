//
// Created by kimiho on 4/16/23.
//

#include "Queue.h"

Queue::Queue() { qfront = qrear = nullptr; }

void Queue::enqueue(int value) {
    Node *newNode = new Node;
    newNode->val = value;
    newNode->next = nullptr;
    if (qfront == nullptr) { qfront = qrear = newNode; }
    else { qrear->next = newNode; qrear = newNode; }
}

void Queue::dequeue() {
    if (qfront == nullptr) return;
    Node *temp = qfront;
    qfront = qfront->next;
    delete temp;
}

int Queue::size() {
    int size = 0;
    Node *tempFront = qfront;
    while (tempFront != nullptr) { size++; tempFront = tempFront->next; }
    return size;
}

void Queue::displayQueue() {
    Node *tempFront = qfront;
    while (tempFront != nullptr) { cout << tempFront->val << " "; tempFront = tempFront->next; }
    cout << endl;
}

int Queue::front() {
    return qfront->val;
}

int Queue::back() {
    return qrear->val;
}

bool Queue::isEmpty() {
    return qfront == nullptr;
}