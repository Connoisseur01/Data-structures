#include "Test.hpp"
#include "Counter.hpp"
#include "../Array.hpp"
#include "../DoublyLinkedList.hpp"
#include "../Heap.hpp"
#include "../RedBlackTree.hpp"
#include<string>
#include<iostream>
#include<fstream>
#include<time.h>

using std::endl;

void Test::generateData(int size, std::string filename){

    std::ofstream file;
    file.open(filename);
    if(!file.is_open()) return;

    file<<size<<endl;

    int element;
    for(int i = 0; i < size; ++i){

        element = rand() % 20000 + 1;
        file<<element<<endl;
    }


    file.close();
}

void Test::testArray(){
    
    std::ofstream arrayAdd, arrayAddBack, arrayAddFront, arrayFind, arrayRemove, arrayRemoveBack, arrayRemoveFront;

    std::string ARRAY_DATA = "../data/array/array.txt";
    std::string ADD_CSV = "../data/array/array_add.csv";
    std::string ADD_BACK_CSV = "../data/array/array_add_back.csv";
    std::string ADD_FRONT_CSV = "../data/array/array_add_front.csv";
    std::string REMOVE_CSV = "../data/array/array_remove.csv";
    std::string REMOVE_BACK_CSV = "../data/array/array_remove_back.csv";
    std::string REMOVE_FRONT_CSV = "../data/array/array_remove_front.csv";
    std::string FIND_CSV = "../data/array/array_find.csv";

    arrayAdd.open(ADD_CSV);
    arrayAddBack.open(ADD_BACK_CSV);
    arrayAddFront.open(ADD_FRONT_CSV);
    arrayRemove.open(REMOVE_CSV);
    arrayRemoveBack.open(REMOVE_BACK_CSV);
    arrayRemoveFront.open(REMOVE_FRONT_CSV);
    arrayFind.open(FIND_CSV);
        
    size = 2000;
    time = 0.0;

    for(int i = 0; i < 15; ++i){ 

        //add 
        for(int k = 0; k < 100; ++k){
            generateData(size, ARRAY_DATA);
            Array array;
            Counter counter;

            counter.startCounter();
            array.addElement(size-1, k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        arrayAdd<<size<<","<<time<<endl;
        time = 0.0;

        //add front
        for(int k = 0; k < 100; ++k){
            generateData(size, ARRAY_DATA);
            Array array;
            Counter counter;

            counter.startCounter();
            array.addFront(k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        arrayAddFront<<size<<","<<time<<endl;
        time = 0.0;

        //add back
        for(int k = 0; k < 100; ++k){
            generateData(size, ARRAY_DATA);
            Array array;
            Counter counter;

            counter.startCounter();
            array.addBack(k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        arrayAddBack<<size<<","<<time<<endl;
        time = 0.0;

        //remove
        for(int k = 0; k < 100; ++k){
            generateData(size, ARRAY_DATA);
            Array array;
            Counter counter;

            counter.startCounter();
            array.removeElement(size-1);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        arrayRemove<<size<<","<<time<<endl;
        time = 0.0;

        //remove front
        for(int k = 0; k < 100; ++k){
            generateData(size, ARRAY_DATA);
            Array array;
            Counter counter;

            counter.startCounter();
            array.removeFront();
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        arrayRemoveFront<<size<<","<<time<<endl;
        time = 0.0;

        //remove back
        for(int k = 0; k < 100; ++k){
            generateData(size, ARRAY_DATA);
            Array array;
            Counter counter;

            counter.startCounter();
            array.removeBack();
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        arrayRemoveBack<<size<<","<<time<<endl;
        time = 0.0;

        //find value
        for(int k = 0; k < 100; ++k){
            generateData(size, ARRAY_DATA);
            Array array;
            Counter counter;
            int* arrayPtr = array.getPointer();

            counter.startCounter();
            array.find(arrayPtr[size-1]);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        arrayFind<<size<<","<<time<<endl;
        time = 0.0;

        size = size+1000;
    }


    arrayAdd.close();
    arrayAddBack.close();
    arrayAddFront.close();
    arrayFind.close();
    arrayRemove.close();
    arrayRemoveFront.close();
    arrayRemoveBack.close();
}

void Test::testList(){
    std::ofstream listAdd, listAddBack, listAddFront, listFind, listRemove, listRemoveBack, listRemoveFront;

    std::string LIST_DATA = "../data/list/list.txt";
    std::string ADD_CSV = "../data/list/list_add.csv";
    std::string ADD_BACK_CSV = "../data/list/list_add_back.csv";
    std::string ADD_FRONT_CSV = "../data/list/list_add_front.csv";
    std::string REMOVE_CSV = "../data/list/list_remove.csv";
    std::string REMOVE_BACK_CSV = "../data/list/list_remove_back.csv";
    std::string REMOVE_FRONT_CSV = "../data/list/list_remove_front.csv";
    std::string FIND_CSV = "../data/list/list_find.csv";

    listAdd.open(ADD_CSV);
    listAddBack.open(ADD_BACK_CSV);
    listAddFront.open(ADD_FRONT_CSV);
    listRemove.open(REMOVE_CSV);
    listRemoveBack.open(REMOVE_BACK_CSV);
    listRemoveFront.open(REMOVE_FRONT_CSV);
    listFind.open(FIND_CSV);
    
    size = 2000;
    time = 0.0;

    for(int i = 0; i < 15; ++i){ 

        //add 
        for(int k = 0; k < 100; ++k){
            generateData(size, LIST_DATA);
            DoublyLinkedList list;
            Counter counter;

            counter.startCounter();
            list.addElement(size-1, k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        listAdd<<size<<","<<time<<endl;
        time = 0.0;

        //add front
        for(int k = 0; k < 100; ++k){
            generateData(size, LIST_DATA);
            DoublyLinkedList list;
            Counter counter;

            counter.startCounter();
            list.addFront(k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        listAddFront<<size<<","<<time<<endl;
        time = 0.0;

        //add back
        for(int k = 0; k < 100; ++k){
            generateData(size, LIST_DATA);
            DoublyLinkedList list;
            Counter counter;

            counter.startCounter();
            list.addBack(k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        listAddBack<<size<<","<<time<<endl;
        time = 0.0;

        //remove
        for(int k = 0; k < 100; ++k){
            generateData(size, LIST_DATA);
            DoublyLinkedList list;
            Counter counter;

            counter.startCounter();
            list.removeElement(size - 1);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        listRemove<<size<<","<<time<<endl;
        time = 0.0;

        //remove front
        for(int k = 0; k < 100; ++k){
            generateData(size, LIST_DATA);
            DoublyLinkedList list;
            Counter counter;

            counter.startCounter();
            list.removeFront();
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        listRemoveFront<<size<<","<<time<<endl;
        time = 0.0;

        //remove back
        for(int k = 0; k < 100; ++k){
            generateData(size, LIST_DATA);
            DoublyLinkedList list;
            Counter counter;

            counter.startCounter();
            list.removeBack();
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        listRemoveBack<<size<<","<<time<<endl;
        time = 0.0;

        //find value
        for(int k = 0; k < 100; ++k){
            generateData(size, LIST_DATA);
            DoublyLinkedList list;
            Counter counter;
            ListElement* last = list.getLast();

            counter.startCounter();
            list.find(last->prev->value);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        listFind<<size<<","<<time<<endl;
        time = 0.0;

        size = size+1000;
    }


    listAdd.close();
    listAddBack.close();
    listAddFront.close();
    listFind.close();
    listRemove.close();
    listRemoveFront.close();
    listRemoveBack.close();
}

void Test::testHeap(){

    std::ofstream heapAdd, heapRemove, heapFind;

    std::string HEAP_DATA = "../data/heap/heap.txt";
    std::string ADD_CSV = "../data/heap/heap_add.csv";
    std::string REMOVE_CSV = "../data/heap/heap_remove.csv";
    std::string FIND_CSV = "../data/heap/heap_find.csv";

    heapAdd.open(ADD_CSV);
    heapRemove.open(REMOVE_CSV);
    heapFind.open(FIND_CSV);

    size = 2000;
    time = 0.0;

    for(int i = 0; i < 15; ++i){ 

        //add 
        for(int k = 0; k < 100; ++k){
            generateData(size, HEAP_DATA);
            MaxHeap heap;
            Counter counter;

            counter.startCounter();
            heap.push(k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        heapAdd<<size<<","<<time<<endl;
        time = 0.0;

        //remove
        for(int k = 0; k < 100; ++k){
            generateData(size, HEAP_DATA);
            MaxHeap heap;
            Counter counter;

            counter.startCounter();
            heap.removeRoot();
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        heapRemove<<size<<","<<time<<endl;
        time = 0.0;

        //find
        for(int k = 0; k < 100; ++k){
            generateData(size, HEAP_DATA);
            MaxHeap heap;
            Counter counter;
            int* heapPtr = heap.getHeap();

            counter.startCounter();
            heap.find(heapPtr[size-1]);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        heapFind<<size<<","<<time<<endl;
        time = 0.0;

        size = size + 1000;
    }
    heapAdd.close();
    heapRemove.close();
    heapFind.close();
}

void Test::testRedBlackTree(){
    std::ofstream rbtAdd, rbtRemove, rbtFind;

    std::string RBT_DATA = "../data/rbt/rbt.txt";
    std::string ADD_CSV = "../data/rbt/rbt_add.csv";
    std::string REMOVE_CSV = "../data/rbt/rbt_remove.csv";
    std::string FIND_CSV = "../data/rbt/rbt_find.csv";

    rbtAdd.open(ADD_CSV);
    rbtRemove.open(REMOVE_CSV);
    rbtFind.open(FIND_CSV);

    size = 2000;
    time = 0.0;

    for(int i = 0; i < 15; ++i){ 

        //add 
        for(int k = 0; k < 100; ++k){
            generateData(size, RBT_DATA);
            RedBlackTree rbt;
            Counter counter;

            counter.startCounter();
            rbt.push(k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        rbtAdd<<size<<","<<time<<endl;
        time = 0.0;

        //remove
        for(int k = 0; k < 100; ++k){
            generateData(size, RBT_DATA);
            RedBlackTree rbt;
            Counter counter;

            counter.startCounter();
            rbt.remove(k);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        rbtRemove<<size<<","<<time<<endl;
        time = 0.0;

        //find
        for(int k = 0; k < 100; ++k){
            generateData(size, RBT_DATA);
            RedBlackTree rbt;
            Counter counter;

            counter.startCounter();
            rbt.find(rand() % 20000);
            counter.stopCounter();
            time = time + counter.getCounter();
        }

        time = time /100;
        rbtFind<<size<<","<<time<<endl;
        time = 0.0;

        size = size + 1000;
    }
    rbtAdd.close();
    rbtRemove.close();
    rbtFind.close();
}