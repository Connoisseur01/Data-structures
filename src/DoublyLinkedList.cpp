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

int DoublyLinkedList::find(int value){
    ListElement* iterator = head;
    int index = 0;
    while(iterator != nullptr){
        if(iterator->value == value){
            return index;
        }
        iterator = iterator->next;
        ++index;
    }
    return -1;
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

bool DoublyLinkedList::addElement(int index, int value){

    ListElement* iterator = head;
    for(int i = 0 ; i < index; i++){
        if(iterator->next == nullptr){
            return false;
        }

        iterator = iterator->next;
    }

    if(iterator == head){
        head = new ListElement();
        head->value = value;
        last = head;
        return true;
    }
    else{
        ListElement* newData = new ListElement();
        newData->value = value;
        newData->next = iterator;
        newData->prev = iterator->prev;
        if(iterator->prev == nullptr){
            head = newData;
        }
        else{
            iterator->prev->next = newData;
        }
        iterator->prev = newData;
        return true;
    }
}

bool DoublyLinkedList::removeBack(){
    if(last == nullptr){
        return false;
    }
    else{
        ListElement* current = last;
        if(last->prev != nullptr){
        last = last->prev;
        last->next = nullptr;
        }
        else{
            last = nullptr;
            head = nullptr;
        }
        delete current;
        return true;
    }
}

bool DoublyLinkedList::removeFront(){
    if(head == nullptr){
        return false;
    }
    else{
        ListElement* current = head;
        if(head->next != nullptr){
        head = head->next;
        head->prev = nullptr;
        }
        else{
            head = nullptr;
            last = nullptr;
        }
        delete current;
        return true;
    }
}

bool DoublyLinkedList::removeElement(int index){
    ListElement* iterator = head;
    for(int i = 0 ; i < index; i++){
        if(iterator->next == nullptr){
            return false;
        }

        iterator = iterator->next;
    }

    if(iterator->prev != nullptr){
        iterator->prev->next = iterator->next;
    }
    else{
        head = iterator->next;
    }

    if(iterator->next != nullptr){
        iterator->next->prev = iterator->prev;
    }
    else{
        last = iterator->prev;
    }

    delete iterator;
    return true;
}

void DoublyLinkedList::printList(){
    ListElement* current = head;
    std::cout<<"\nlist: ";
    while(current != nullptr){
        std::cout<< current->value << " ";
        current = current->next;    
    }
    std::cout<<"\n";
}

void DoublyLinkedList::menu(){
    int option = 0;
    int value;
    int index;

    while(true){
        std::cout<<endl<<"---------------------------------"<<endl;
        printList();
        std::cout<<endl<<"[1] add element to the back of the list"<<endl
                    <<"[2] add element to the front of the list"<<endl
                    <<"[3] add element add a given index"<<endl
                    <<"[4] remove last element"<<endl
                    <<"[5] remove first element"<<endl
                    <<"[6] remove element at a given index"<<endl
                    <<"[7] find index of an element"<<endl
                    <<"[8] return"<<endl;

        std::cin>>option;

        switch (option){

        case 1:     //add element to the back of the list
            std::cout<<"element value: ";
            std::cin>>value;
            addBack(value);
            std::cout<<"element added";
            break;
        
        case 2:     //add element to the front of the list
            std::cout<<"element value: ";
            std::cin>>value;
            addFront(value);
            std::cout<<"element added";
            break;
            
        case 3:     //add element at a given index
            std::cout<<"element value: ";
            std::cin>>value;
            std::cout<<"element index: ";
            std::cin>>index;
            if(addElement(index, value)){
                std::cout<<"element added";
            }
            else{
                std::cout<<"no element at the given index";
            }
            break;
        
        case 4:     //remove element from the back
            if(removeBack()){
                std::cout<<"element deleted";
            }
            else{
                std::cout<<"list is empty";
            }
            break;

        case 5:     //remove element from the front
            if(removeFront()){
                std::cout<<"element deleted";
            }
            else{
                std::cout<<"list is empty";
            }
            break;

        case 6:     //remove element at index
            std::cout<<"element index: ";
            std::cin>>index;
            if(removeElement(index)){
                std::cout<<"element deleted";
            }
            else{
                std::cout<<"no element at the given index";
            }
            break;

        case 7:     //find element
            std::cout<<"element value: ";
            std::cin>>value;
            index = find(value);
            if(index == -1){
                std::cout<<"value is not in the list";
            }
            else{
                std::cout<<"value at index: "<<index;
            }
            break;

        case 8:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }
        
    }
}