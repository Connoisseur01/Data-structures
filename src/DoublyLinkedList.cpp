#include <iostream>
#include "DoublyLinkedList.hpp"
using std::endl;
        
DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
     last = head;
}

DoublyLinkedList::~DoublyLinkedList(){
    ListElement* iterator = head;
    while(iterator != nullptr) {
        ListElement* current = iterator;
        iterator = iterator->next;
        delete current;
    }
}

void DoublyLinkedList::addBack(int value){
    
    if(last == nullptr){
        head = new ListElement();
        last = head;
    }
    else{
        last->next = new ListElement();
        last->next->prev = last;
        last = last->next;
    }
    last->value = value;
}

void DoublyLinkedList::addFront(int value){

    if(head == nullptr){
        head = new ListElement();
        last = head;        
    }
    else{
        head->prev = new ListElement();
        head->prev->next = head;
        head = head->prev;
    }
    head->value = value;
}

void DoublyLinkedList::addElement(int index, int value){

}

void DoublyLinkedList::printList(){
    ListElement* current = head;
    while(current != nullptr){
        std::cout<< current->value << " | ";
        current = current->next;    
    }
    std::cout<<"\n";
}

void DoublyLinkedList::menu(){
    int option = 0;
    while(true){
        std::cout<<endl<<"---------------------------------"<<endl
            <<"(1) add element to the back of the list"<<endl
            <<"(2) add element to the front of the list"<<endl
            <<"(3) print list"<<endl
            <<"(4) return"<<endl;
        std::cin>>option;
        switch (option){
        case 1:
            int value;
            std::cout<<"element value: ";
            std::cin>>value;
            addBack(value);
            std::cout<<"element added";
            break;
        
        case 2:
            int value;
            std::cout<<"element value: ";
            std::cin>>value;
            addFront(value);
            std::cout<<"element added";
            break;
            
        case 3:
            printList();
            break;
        case 4:
            return;
        default:
            std::cout<<"wrong input";
            break;
        }
        
    }
}