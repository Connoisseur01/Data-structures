#include <iostream>
#include <fstream>
#include "Heap.hpp"
using std::endl;

MaxHeap::MaxHeap(){
    read();
}

MaxHeap::~MaxHeap(){
    if(heap != nullptr)
        delete[] heap;
}

void MaxHeap::read(){

    std::ifstream input("../data/heap/heap.txt");
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
    if(left < size){
        if(heap[left] > heap[largest])
        largest = left;
    }
    if(right < size){
        if(heap[right]>heap[largest])
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

        while(heap[parent(i)] < value && parent(i) >= 0){

            int temp = heap[parent(i)];
            heap[parent(i)] = value;
            heap[i] = temp;
            i = parent(i);
        }
      
    ++size;
}

void MaxHeap::removeRoot(){
    if(heap == nullptr) return;
    if(heap+1 == nullptr){
        delete[] heap;
    }
    else{
        heap[0] = heap[size - 1];
        heapify(0);
        heap = (int*) realloc(heap, (size-1)*sizeof(int));
        --size;
    }
}

void MaxHeap::print(){
    int numberOfElementsInRow = 1;
    int maxRowElements = 1;

    for(int i = 0; i < size; ++i, ++numberOfElementsInRow){

        std::cout<<heap[i]<<" ";

        if(numberOfElementsInRow == maxRowElements){

            std::cout<<endl;
            maxRowElements = maxRowElements * 2;
            numberOfElementsInRow = 0;

        }

    }
    std::cout<<endl;
}

int MaxHeap::find(int value){

   for(int i = 0; i < size; ++i){
       if(heap[i] == value){
           return i;
       }
   } 
   return -1;
}

void MaxHeap::menu(){
    int option = 0;
    int value;
    while(true){
        std::cout<<endl<<"--------------------------------"<<endl;
        print();
        std::cout<<endl<<"[1] add element to heap"<<endl
                    <<"[2] remove root"<<endl
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
            removeRoot();
            std::cout<<"root removed";
            break;

        case 3:
            std::cout<<"elements value: ";
            std::cin>>value;
            std::cout<<"elements index -> "<<find(value);
            break;
        
        case 4:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }
    }
}