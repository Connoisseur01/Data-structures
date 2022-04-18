#include "Array.hpp"
#include <iostream>
#include <fstream> 
using std::endl;

Array::Array(){
    read();
}

Array::~Array(){
 delete[] array;
}

void Array::read(){

    std::ifstream input("../data/array/array.txt");
    if(!input.is_open()){
        return;
    }
    int numberOfElements;
    input >> numberOfElements;
    int element;
    for(int i = 0; i < numberOfElements; ++i){
        input >> element;
        addBack(element);
    }
    input.close();
}

void Array::addBack(int value){

    if(array == nullptr){

        array = new int[1];

    }
    else{

        int* newArray = new int[size+1];

        for(int i = 0; i < size; ++i){
            newArray[i] = array[i];
         }

        int* prevArray = array;
        array = newArray;
        delete[] prevArray;
    }

    ++size; 
    array[size-1] = value;
}

void Array::addFront(int value){
    if(array == nullptr){
        array = new int[1];
    }
    else{

        int* newArray = new int[size+1];

        for(int i = 1; i <= size; ++i){
            newArray[i] = array[i-1];
         }

        int* prevArray = array;
        array = newArray;
        delete[] prevArray;
    }

    ++size;
    array[0] = value;
}

bool Array::addElement(int index, int value){

    if(index < 0 || index > size-1){
        return false;
    }

    if(array == nullptr){
        array = new int[1];
    }
    else{
        int* newArray = new int[size+1];

        int current = 0;
        for(int i = 0; i < size; ++i, ++current){
            if(current == index){
                newArray[current] = value;
                --i;
            }
            else{
                newArray[current] = array[i];
            }
         }

        int* prevArray = array;
        array = newArray;
        delete[] prevArray;
    }

    ++size;
    array[index] = value;
    return true;
}

bool Array::removeBack(){
    if(array == nullptr){
        return false;       
    }
    
    if(size == 1){
        delete[] array;
        array = nullptr;
    }
    else{
        int* newArray = new int[size-1];

        for(int i = 0; i < size-1; ++i){
            newArray[i] = array[i];
        }

        int* prevArray = array;
        array = newArray;
        delete[] prevArray;
    }
    --size;
    return true;
}

bool Array::removeFront(){
    if(array == nullptr){
        return false;       
    }
    
    if(size == 1){
        delete[] array;
        array = nullptr;
    }
    else{
        int* newArray = new int[size - 1];

        for(int i = 1; i < size; ++i){
            newArray[i-1] = array[i];
        }

        int* prevArray = array;
        array = newArray;
        delete[] prevArray;
    }
    --size;
    return true;
}

bool Array::removeElement(int index){

    if(index < 0 || index > size-1 || array == nullptr){
        return false;
    }
    if(size == 1){
        delete[] array;
        array=nullptr;
    }
    else{
        int* newArray = new int[size - 1];

        int current = 0;
        for(int i = 0; i < size; ++i, ++current){
            if(i == index){
                --current;
            }
            else{
                newArray[current] = array[i];
            }
            
        }

        int* prevArray = array;
        array = newArray;
        delete[] prevArray;
    }
    --size;
    return true;
}

int Array::find(int value){

    for(int i = 0; i < size; ++i){
        if(array[i] == value){
            return i;
        }
    }
    return -1;
}

void Array::print(){

    std::cout<<"\nArray: ";

    for(int i=0; i < size; ++i){
        std::cout<<array[i]<<" ";
    }
}

void Array::menu(){
    int option = 0;
    int value;
    int index;

    while(true){
        std::cout<<endl<<"---------------------------------"<<endl;
        print();
        std::cout<<endl<<"[1] add element to the back of the array"<<endl
                    <<"[2] add element to the front of the array"<<endl
                    <<"[3] add element at a given index"<<endl
                    <<"[4] remove last element"<<endl
                    <<"[5] remove first element"<<endl
                    <<"[6] remove element at a given index"<<endl
                    <<"[7] find index of an element"<<endl
                    <<"[8] return"<<endl;

        std::cin>>option;

        switch (option){

        case 1:     //add element to the back of the array
            std::cout<<"element value: ";
            std::cin>>value;
            addBack(value);
            std::cout<<"element added";
            break;
        
        case 2:     //add element to the front of the array
            std::cout<<"element value: ";
            std::cin>>value;
            addFront(value);
            std::cout<<"element added";
            break;
            
        case 3:     //add element at a given index
            std::cout<<"element value: ";
            std::cin>>value;
            std::cout<<"element index: ";
            std::cin>>index;
            if(addElement(index, value)){
                std::cout<<"element added";
            }
            else{
                std::cout<<"no element at the given index";
            }
            break;
        
        case 4:     //remove element from the back
            if(removeBack()){
                std::cout<<"element deleted";
            }
            else{
                std::cout<<"array is empty";
            }
            break;

        case 5:     //remove element from the front
            if(removeFront()){
                std::cout<<"element deleted";
            }
            else{
                std::cout<<"array is empty";
            }
            break;

        case 6:     //remove element at index
            std::cout<<"element index: ";
            std::cin>>index;
            if(removeElement(index)){
                std::cout<<"element deleted";
            }
            else{
                std::cout<<"no element at the given index";
            }
            break;

        case 7:     //find element
            std::cout<<"element value: ";
            std::cin>>value;
            index = find(value);
            if(index == -1){
                std::cout<<"value is not in the array";
            }
            else{
                std::cout<<"value at index: "<<index;
            }
            break;

        case 8:
            return;

        default:
            std::cout<<"wrong input";
            break;
        }
        
    }
}