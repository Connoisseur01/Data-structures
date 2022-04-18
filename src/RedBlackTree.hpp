#pragma once

struct Node{

    int value;
    char color;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

class RedBlackTree{
    private:

        Node* root = nullptr;
        Node* leaf;

        int size = 0;
        void deleteChildren(Node* node);
        void fixPush(Node* node);
        void fixRemove(Node* Node);
        void transplant(Node* prev, Node* newNode);
        void read();

    public:

    RedBlackTree();
    ~RedBlackTree();

    void rotateLeft(Node* x);
    void rotateRight(Node* x);
    void push(int value);
    void remove(int value);
    void menu();
    void print(Node* node, int indent = 0);
    Node* find(int value);

};
