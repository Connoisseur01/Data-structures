#include <iostream>
#include "List.hpp"
using std::endl;
        
LinkedList::LinkedList(){
    head = nullptr;
     last = head;
}

LinkedList::~LinkedList(){
    ListElement* iterator = head;
    while(iterator != nullptr) {
        ListElement* prev = iterator;
        iterator = iterator->next;
        delete prev;
    }
}

void LinkedList::addElement(int value){
    
    if(last == nullptr){
        head = new ListElement();
        last = head;
    }
    else{
        last->next = new ListElement();
        last = last->next;
    }
    last->value = value;
}

void LinkedList::printList(){
    ListElement* current = head;
    while(current != nullptr){
        std::cout<< current->value << " | ";
        current = current->next;    
    }
    std::cout<<"\n";
}

void LinkedList::menu(){
    int option = 0;
    while(true){
        std::cout<<endl<<"---------------------------------"<<endl
            <<"(1) add element to list"<<endl
            <<"(2) print list"<<endl
            <<"(3) return"<<endl;
        std::cin>>option;
        switch (option){
        case 1:
            int value;
            std::cout<<"element value: ";
            std::cin>>value;
            addElement(value);
            std::cout<<"element added";
            break;
        
        case 2:
            printList();
            break;
        case 3:
            return;
        default:
            std::cout<<"wrong input";
            break;
        }
        
    }
}