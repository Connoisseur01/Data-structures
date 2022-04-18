#include "RedBlackTree.hpp"
#include <iostream>
#include <fstream>

using std::endl;

RedBlackTree::RedBlackTree(){
    leaf = new Node;
    leaf->color = 'B';
    leaf->left = nullptr;
    leaf->right = nullptr;
    root = leaf;
    read();
}

RedBlackTree::~RedBlackTree(){

    if(root != nullptr){
        deleteChildren(root);
    }
}

void RedBlackTree::read(){
    
    std::ifstream input("../data/rbt/rbt.txt");
    if(!input.is_open()){
        return;
    }
    int numberOfElements;
    input >> numberOfElements;
    int element;
    for(int i = 0; i < numberOfElements; ++i){
        input >> element;
        push(element);
    }
    input.close();
}

void RedBlackTree::deleteChildren(Node* node){
    if(node->left != leaf){
        deleteChildren(node->left);
    }
    if(node->right != leaf){
        deleteChildren(node->right);
    }
    delete node;
}

void RedBlackTree::print(Node* node, int indent){

    if(node != leaf) {
        if (indent != 0) {
            for(int i = 0; i < indent-4; ++i){
                std::cout<<" ";
            }
            std::cout<<"|-->";
        }          
        std::cout<< node->value<<node->color<<endl;

        if(node->left) print(node->left, indent+4);
        if(node->right) print(node->right, indent+4);
    }
}

void RedBlackTree::rotateLeft(Node* x){

    if(x->right == leaf){
        return;
    }

    Node* y = x->right;
    x->right = y->left;
    
    if (y->left != leaf) {
      y->left->parent = x;
    
    }
    
    y->parent = x->parent;
    if (x->parent == nullptr) {
    
      root = y;
    
    } else if (x == x->parent->left) {
    
      x->parent->left = y;
    
    } else {
    
      x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rotateRight(Node* x){
    if(x->left == leaf){
        return;
    }

    Node* y = x->left;
    x->left = y->right;
    
    if (y->right != leaf) {
      y->right->parent = x;
    }
    
    y->parent = x->parent;
    
    if (x->parent == nullptr) {
    
      root = y;
    
    } else if (x == x->parent->right) {
    
      x->parent->right = y;
    
    } else {
    
      x->parent->left = y;
    }
    
    y->right = x;
    x->parent = y;
}

void RedBlackTree::push(int value){
    
    Node* node = new Node;
    node->value = value;
    node->color = 'R';
    node->left = leaf;
    node->right = leaf;

    Node* current = root;
    Node* prev = nullptr;

    if(root == leaf){
        root = node;
    }
    else{

        while(current != leaf){

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

    if(node->parent == nullptr){
        node->color = 'B';
        return;
    }

    if(node->parent->parent == nullptr){
        return;
    }

    fixPush(node);
}

void RedBlackTree::fixPush(Node* node){

    Node* uncle;

    while (node->parent->color == 'R') {

      if (node->parent == node->parent->parent->right) {
        
        uncle = node->parent->parent->left;
        
        if (uncle->color == 'R') {
        
          uncle->color = 'B';
          node->parent->color = 'B';
          node->parent->parent->color = 'R';
          node = node->parent->parent;
        } else {
        
          if (node == node->parent->left) {
            node = node->parent;
            rotateRight(node);
          }
        
          node->parent->color = 'B';
          node->parent->parent->color = 'R';
          rotateLeft(node->parent->parent);
        }
      } else {
        
        uncle = node->parent->parent->right;

        if (uncle->color == 'R') {
        
          uncle->color = 'B';
          node->parent->color = 'B';
          node->parent->parent->color = 'R';
          node = node->parent->parent;
        } else {
        
          if (node == node->parent->right) {
            node = node->parent;
            rotateLeft(node);
          }
        
          node->parent->color = 'B';
          node->parent->parent->color = 'R';
          rotateRight(node->parent->parent);
        }
      }
      if (node == root) {
        break;
      }
    }
    root->color = 'B';
}

void RedBlackTree::transplant(Node* prev, Node* newNode) {
    
    if (prev->parent == nullptr) {
      root = newNode;
    } else if (prev == prev->parent->left) {
      prev->parent->left = newNode;
    } else {
      prev->parent->right = newNode;
    }

   newNode->parent = prev->parent;
    
  }

void RedBlackTree::fixRemove(Node* node){

    Node* sibling;
    
    while (node != root && node->color == 'B') {
    
      if (node == node->parent->left) {
    
        sibling = node->parent->right;
    
        if (sibling->color == 'R') {
    
          sibling->color = 'B';
          node->parent->color = 'R';
          rotateLeft(node->parent);
          sibling = node->parent->right;
        }

        if (sibling->left->color == 'B' && sibling->right->color == 'B') {
    
          sibling->color = 'R';
          node = node->parent;
        } else {
          if (sibling->right->color == 'B') {
    
            sibling->left->color = 'B';
            sibling->color = 'R';
            rotateRight(sibling);
            sibling = node->parent->right;
          }

          sibling->color = node->parent->color;
          node->parent->color = 'B';
          sibling->right->color = 'B';
          rotateLeft(node->parent);
          node = root;
        }
      } else {
    
        sibling = node->parent->left;
    
        if (sibling->color == 'R') {
    
          sibling->color = 'B';
          node->parent->color = 'R';
          rotateRight(node->parent);
          sibling = node->parent->left;
        }

        if (sibling->right->color == 'B' && sibling->right->color == 'B') {
    
          sibling->color = 'R';
          node = node->parent;
        } else {
    
          if (sibling->left->color == 'B') {
    
            sibling->right->color = 'B';
            sibling->color = 'R';
            rotateLeft(sibling);
            sibling = node->parent->left;
          }

          sibling->color = node->parent->color;
          node->parent->color = 'B';
          sibling->left->color = 'B';
          rotateRight(node->parent);
          node = root;
        }
      }
    }
    node->color = 'B';
}

void RedBlackTree::remove(int value){

    Node* node = find(value);
    if(node == nullptr){
      return;
    }
    Node *x, *y;

    y = node;
    char y_original_color = y->color;
    
    if (node->left == leaf) {
      x = node->right;
      transplant(node, node->right);
    } 
    else if (node->right == leaf) {
      x = node->left;
      transplant(node, node->left);
    } 
    else {
    
    //assigning the minimum of right subtree of node to be deleted to y
        y = node->right;
    
        while(y->left != leaf){
            y = y->left;
        }
    
        y_original_color = y->color;
        x = y->right;
    
        if (y->parent == node) {
    
            x->parent = y;
        } 
        else {
    
            transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
      }

        transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    
    delete node;
    if (y_original_color == 0) {
      fixRemove(x);
    }
}

Node* RedBlackTree::find(int value){

    Node* current = root;

    while (current != leaf)
    {
        if(current->value == value){
            return current;
        }

        if(current->value < value){
            current = current->right;
        }
        else{
            current = current->left;
        }
    }

    return nullptr;
}

void RedBlackTree::menu(){
    int option = 0;
    int value;
    while(true){
        std::cout<<endl<<"--------------------------------"<<endl;
        print(root);
        std::cout<<endl<<"[1] add element to tree"<<endl
                    <<"[2] remove element"<<endl
                    <<"[3] find index of an element"<<endl
                    <<"[4] return"<<endl;
        std::cin>>option;

        switch (option){

        case 1:
            std::cout<<"element value: ";
            std::cin>>value;
            push(value);
            break;

        case 2:
            std::cout<<"element value: ";
            std::cin>>value;
            remove(value);
            break;       
        
        case 4:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }
    }
}