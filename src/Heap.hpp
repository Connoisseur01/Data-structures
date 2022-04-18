#pragma once

class MaxHeap  
{
private:

    int size = 0;
    int* heap = nullptr;

    int parent(int i);
    int left(int i);
    int right(int i);
    void read();

public:

    MaxHeap();
    ~MaxHeap();

    void heapify(int i);
    void push(int value);
    void removeRoot();
    void menu();
    void print();
    int find(int value);
    inline int* getHeap(){return heap;}

};