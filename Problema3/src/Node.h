#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    std::string word;
    Node* left;
    Node* right;

    Node(std::string w) : word(w), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
