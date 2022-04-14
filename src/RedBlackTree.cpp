#include "RedBlackTree.hpp"
#include <iostream>

using std::endl;

RedBlackTree::~RedBlackTree(){

    if(root != nullptr){
        deleteChildren(root);
    }
}

void RedBlackTree::deleteChildren(Node* node){
    if(node->left != nullptr){
        deleteChildren(node->left);
    }
    if(node->right != nullptr){
        deleteChildren(node->right);
    }
    delete node;
}

void RedBlackTree::print(Node* node, int indent){

    if(node != nullptr) {
        if (indent != 0) {
            for(int i = 0; i < indent-4; ++i){
                std::cout<<" ";
            }
            std::cout<<"|-->";
        }          
        std::cout<< node->value << node->color << "\n ";

        if(node->left) print(node->left, indent+4);
        if(node->right) print(node->right, indent+4);
    }
}

void RedBlackTree::leftRotate(Node* x){

    if(x->right == nullptr){
        return;
    }

    Node* y = x->right;

    if(y->left != nullptr){
        y->left->parent = x;
        x->right = y->left;
    }
    else{
        x->right = nullptr;
    }

    if(x->parent != nullptr){
        y->parent = x->parent;
    }
    
    if(x->parent == nullptr){
        root = y;    
    }
    else{

        if(x == x->parent->left){
            x->parent->left = y;
        }
        else{
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
}

void RedBlackTree::rightRotate(Node* x){
    if(x->left == nullptr){
        return;
    }

    Node* y = x->left;
    if(y->right != nullptr){
        x->left = y->right;
        y->right->parent = x;
    }
    else{
        x->left = nullptr;
    }

    if(x->parent != nullptr){
        y->parent = x->parent;
    }
    if(x->parent == nullptr){
        root = y;
    }
    else{
        if(x == x->parent->left){
            x->parent->left = y;
        }
        else{
            x->parent->right = y;
        }
        y->right = x;
        x->parent = y;
    }
}

void RedBlackTree::push(int value){
    
    Node* node = new Node;
    node->value = value;
    node->color = 'R';

    Node* current = root;
    Node* prev = nullptr;

    if(root == nullptr){
        root = node;
    }
    else{

        while(current != nullptr){

            prev=current;
            if(node->value > current->value){
                current = current->right;
            }
            else{
                current = current->left;
            }
        }

        node->parent = prev;
        if(node->value > prev->value){
            prev->right = node;
        }
        else{
            prev->left = node;
        }
    }

    pushFix(node);
}

void RedBlackTree::pushFix(Node* node){

    Node* uncle;

    if(root == node){
        node->color = 'B';
        return;
    }

    while(node->parent != nullptr && node->parent->color == 'R'){

        Node* grandparent = node->parent->parent;

        if(grandparent->left == node->parent){

            if(grandparent->right != nullptr){

                uncle = grandparent->right;
                
                if(uncle->color == 'R'){
                    node->parent->color = 'B';
                    uncle->color = 'B';
                    grandparent->color = 'R';
                    node = grandparent;
                }
            }
            else{

                if(node->parent->right == node){
                    node = node->parent;
                    leftRotate(node);
                }

                node->parent->color = 'B';
                grandparent->color = 'R';
                rightRotate(grandparent);
            }
        }
        else{

            if(grandparent->left != nullptr){

                uncle = grandparent->left;
                if(uncle->color == 'R'){

                    node->parent->color = 'B';
                    uncle->color = 'B';
                    grandparent->color = 'R';
                    node = grandparent;
                }
            }
            else{

                if(node->parent->left == node){

                    node = node->parent;
                    rightRotate(node);
                }

                node->parent->color = 'B';
                grandparent->color = 'R';
                leftRotate(grandparent);
            }
        }        
        root->color = 'B';
    }
}

void RedBlackTree::menu(){
    int option = 0;
    int value;
    while(true){
        std::cout<<endl<<"--------------------------------"<<endl;
        print(root);
        std::cout<<endl<<"[1] add element to tree"<<endl
                    <<"[2] remove root"<<endl
                    <<"[3] find index of an element"<<endl
                    <<"[4] return"<<endl;
        std::cin>>option;

        switch (option){

        case 1:
            std::cout<<"element value: ";
            std::cin>>value;
            push(value);
            break;

        
        
        case 4:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }
    }
}