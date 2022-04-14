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
        int size = 0;
        void deleteChildren(Node* node);
        void pushFix(Node* node);

    public:

    ~RedBlackTree();

    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void push(int value);
    //void removeRoot();
    void menu();
    void print(Node* node, int indent = 0);
    //int find(int value);

};
