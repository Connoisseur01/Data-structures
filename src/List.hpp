#pragma once

struct ListElement {
    int value = 0;
    ListElement* next = nullptr;
};
         
         
class LinkedList {
    private:

        ListElement* head;
        ListElement* last;

    public:

        LinkedList();
        ~LinkedList();
        
        void addElement(int value);
        void printList();
        void menu();

};