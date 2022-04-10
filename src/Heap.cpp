#include <iostream>
#include "Heap.hpp"
using std::endl;

MaxHeap::~MaxHeap(){
    if(heap != nullptr)
        delete[] heap;
}

int MaxHeap::right(int i){
    return i*2+2;
}

int MaxHeap::left(int i){
    return i*2+1;
}

int MaxHeap::parent(int i){
 return (i-1)/2;
}

void MaxHeap::heapify(int i){

    int left = this->left(i);
    int right = this->right(i);
    int largest;
    largest = i;
    if(heap[left] > heap[largest] && left <= size){
        largest = left;
    }
    if(heap[right]>heap[largest] && right <= size){
        largest = right;
    }

    if(largest != i){
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest);
    }
}

void MaxHeap::push(int value){

    heap = (int*) realloc(heap, (size+1)*sizeof(int));
    int i = size;
    heap[i] = value;
    if(parent(i) >= 0){
        while(heap[parent(1)] < value){
            int temp = heap[parent(i)];
            heap[parent(i)] = value;
            heap[i] = temp;
        }
    }  
}

void MaxHeap::floydAlgorithm(){

    //int current = parent(size-1);
    //while(heap[current] != NULL){
    //    heapify(current);
    //    --current;
    //}
}

void MaxHeap::removeRoot(){
    if(heap+1 == nullptr){
        delete[] heap;
    }
    else{
        heap[0] = heap[size - 1];
        heapify(0);
        heap = (int*) realloc(heap, (size-1)*sizeof(int));
    }
}

void MaxHeap::menu(){
    int option = 0;
    while(true){
        std::cout<<endl<<"--------------------------------"<<endl
                <<"(1) add element to heap"<<endl
                <<"(2) remove root"<<endl
                <<"(3) create heap from table(Floyd Algorithm)"<<endl
                <<"(4) return"<<endl;
        std::cin>>option;

        switch (option){

        case 1:
            int value;
            std::cout<<"element value: ";
            std::cin>>value;
            push(value);
            break;

        case 2:
            removeRoot();
            std::cout<<"root removed";
            break;

        case 3:
            break;
        
        case 4:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }

    }
}