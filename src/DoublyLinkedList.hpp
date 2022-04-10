#pragma once

struct ListElement {
    int value = 0;
    ListElement* next = nullptr;
    ListElement* prev = nullptr;
};
         
         
class DoublyLinkedList {
    private:

        ListElement* head;
        ListElement* last;

    public:

        DoublyLinkedList();
        ~DoublyLinkedList();
        
        void addBack(int value);
        void addFront(int value);
        void addElement(int index, int value);
        void printList();
        void menu();

};