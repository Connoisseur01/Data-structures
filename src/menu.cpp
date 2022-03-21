#include <iostream>
#include "Heap.hpp"
#include "List.hpp"
using std::endl;

void menu();
int option;

int main(){

    menu();
    return 0;
}

void menu(){
    
    while(true){
        std::cout<<endl<<"---------------------------------"<<endl
            <<"choose data structure:"<<endl
            <<"(1) Linked list"<<endl
            <<"(2) Heap"<<endl
            <<"(3) exit"<<endl;
        std::cin>>option;

        switch (option){

        case 1:{
            LinkedList linkedList;
            linkedList.menu();
            break;
        }
        
        case 2:{
            MaxHeap heap;
            heap.menu();
            break;
        }

        case 3:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }


    }
}