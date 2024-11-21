#ifndef NODE_H
#define NODE_H

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
