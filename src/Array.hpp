#pragma once

class Array{
    private:
        int size = 0;
        int* array = nullptr;

    public:

        ~Array();


         // adds given value as the last element in the list
        void addBack(int value);

        //adds given value as the first element in the list
        void addFront(int value);

        //adds given value at given index
        //returns false if list doesnt have the index
        bool addElement(int index, int value);

        //removes the first list element
        //returns false if the list is empty
        bool removeFront();

        //removes the last list element
        //returns false if the list is empty
        bool removeBack();

        //removes element at given index
        //returns false if list doesnt have the index
        bool removeElement(int index);

        //returns index of the given value or -1 when value hasn't been found
        //if there are multiple elements with the same value in the list returns the first accurence of the value
        int find(int value);
        
        void printArray();
        void menu();

};