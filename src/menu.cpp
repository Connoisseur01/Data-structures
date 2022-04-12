#include <iostream>
#include "Heap.hpp"
#include "DoublyLinkedList.hpp"
#include "Array.hpp"
using std::endl;

void menu();

int main(){

    menu();
    return 0;
}

void menu(){
    
    int option;
    while(true){
        std::cout<<endl<<"---------------------------------"<<endl
            <<"choose data structure:"<<endl
            <<"[1] Array"<<endl
            <<"[2] Doubly Linked list"<<endl
            <<"[3] Heap"<<endl
            <<"[4] exit"<<endl;
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

        case 4:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }


    }
}