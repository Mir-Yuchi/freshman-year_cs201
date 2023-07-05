#include <bits/stdc++.h>

#define MAX_SIZE 5
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

class Stack {
private:
    int q[MAX_SIZE];
    int qfront;

public:
    Stack() {
        qfront = -1;
    }

    void push(int x) {
        if (qfront == MAX_SIZE - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        q[++qfront] = x;
    }

    int pop() {
        if (qfront == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q[qfront--];
    }

    int top() {
        if (qfront == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q[qfront];
    }

    bool empty() {
        return qfront == -1;
    }
};


class MyQueue {
public:
    int qfront;
    MyQueue() {
    }
    stack<int> s;
    void push(int x) {
        s.push(x);
    }
    int pop() {
        if (s.empty()) {
            cout << "Queue is empty";
            return -1;
        }
        int temp = s.top();
        s.pop();
        cout<<temp<< " temp "<<endl;
        if (s.empty()) {
            return temp;
        }

        int elem = pop();
        cout<<elem<<" is elem "<<endl;
        s.push(temp);
        return elem;
    }
    int peek () {
        if (s.empty()) {
            cout << "Queue is empty";
            return -1;
        }
        int temp = s.top();
        s.pop();
        if (s.empty()) {
            s.push(temp);
            return temp;
        }
        int elem = peek();
        s.push(temp);
        return elem;
    }
    bool empty() {
        return s.empty();
    }

};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
//    q.print();
    q.pop();
//    q.print();
}