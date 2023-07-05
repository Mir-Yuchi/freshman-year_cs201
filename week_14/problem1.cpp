#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
-
class BST {
private:
    Node *root;

public:
    BST() { root = nullptr; }

    void insert(int data) {
        Node *newNode = new Node{data, nullptr, nullptr};
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (data < current->data) { current = current->left;}
            else { current = current->right; }
        }

        if (data < parent->data) { parent->left = newNode; }
        else { parent->right = newNode; }
    }

    void inorder(Node *root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node *root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    Node *search(int data) {
        Node *current = root;
        while (current != nullptr && current->data != data) {
            if (data < current->data) { current = current->left; }
            else { current = current->right; }
        }
        return current;
    }

    Node *minValueNode(Node *node) {
        Node *current = node;
        while (current->left != nullptr) { current = current->left; }
        return current;
    }

    Node *maxValueNode(Node *node) {
        Node *current = node;
        while (current->right != nullptr) { current = current->right; }
        return current;
    }

    Node *deleteNode(Node *root, int data) {
        if (root == nullptr) { return root; }

        if (data < root->data) { root->left = deleteNode(root->left, data); }
        else if (data > root->data) { root->right = deleteNode(root->right, data); }
        else {
            if (root->left == nullptr) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    int getMaxLevel(Node *root) {
        if (root == nullptr) { return 0; }

        queue<Node *> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                Node *front = q.front();
                q.pop();

                if (front->left == nullptr && front->right == nullptr) { return level; }

                if (front->left) { q.push(front->left); }

                if (front->right) { q.push(front->right); }
            }
            level++;
        }

        return -1;
    }

    int getMinLevel(Node *root) {
        if (root == nullptr) { return 0; }

        queue<Node *> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                Node *front = q.front();
                q.pop();

                if (front->left == nullptr && front->right == nullptr) { return level; }

                if (front->left) { q.push(front->left); }

                if (front->right) { q.push(front->right); }
            }
            level++;
        }

        return -1;
    }
};
