#pragma once

class MaxHeap  
{
private:

    int size = 0;
    int* heap = nullptr;

    int parent(int i);
    int left(int i);
    int right(int i);

public:

    ~MaxHeap();

    void heapify(int i);
    void push(int value);
    void floydAlgorithm();
    void removeRoot();
    void menu();
    void printHeap();
    int find(int value);

};