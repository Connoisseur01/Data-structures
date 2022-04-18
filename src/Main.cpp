#include <iostream>
#include <time.h>
#include "Heap.hpp"
#include "DoublyLinkedList.hpp"
#include "Array.hpp"
#include "RedBlackTree.hpp"
#include "util/Test.hpp"
using std::endl;

void menu();

int main(){

    srand(time(NULL));

    Test test;
    test.testArray();
    test.testList();
    test.testHeap();
    test.testRedBlackTree();

    /*test.generateData(10, "../data/heap/heap.txt");
    test.generateData(10, "../data/list/list.txt");
    test.generateData(10, "../data/array/array.txt");
    test.generateData(10, "../data/rbt/rbt.txt");
    menu();*/
    return 0;
}

void menu(){
    
    int option;
    while(true){
        std::cout<<endl<<"---------------------------------"<<endl
            <<"choose data structure:"<<endl
            <<"[1] Array"<<endl
            <<"[2] Doubly Linked List"<<endl
            <<"[3] Heap"<<endl
            <<"[4] Red Black Tree"<<endl
            <<"[5] exit"<<endl;
        std::cin>>option;

        switch (option){

        case 1:{
            Array array;
            array.menu();
            break;
        }


        case 2:{
            DoublyLinkedList list;
            list.menu();
            break;
        }
        
        case 3:{
            MaxHeap heap;
            heap.menu();
            break;
        }

        case 4:{
            RedBlackTree tree;
            tree.menu();
            break;
        }

        case 5:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }


    }
}