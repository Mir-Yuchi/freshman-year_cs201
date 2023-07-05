#include "Queue.h"

int main(int argc, const char * argv[]) {

//DO NOT CHANGE MAIN

    Queue q;

    q.enqueue(5);
    q.displayQueue();

    q.enqueue(50);
    q.displayQueue();

    q.enqueue(500);
    q.displayQueue();

    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;

    q.dequeue();
    q.displayQueue();

    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;

    q.enqueue(100);
    q.displayQueue();

    q.dequeue();
    cout<<q.front()<<" "<<q.back()<<endl;
    q.dequeue();
    q.displayQueue();

    q.dequeue();
    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;

    return 0;
}

