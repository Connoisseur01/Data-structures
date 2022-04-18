#pragma once
#include <string>


class Test{
    public:
        void generateData(int size, std::string filename);
        
        void testArray();
        void testList();
        void testHeap();
        void testRedBlackTree();
};