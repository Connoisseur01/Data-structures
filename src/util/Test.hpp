#pragma once
#include <string>


class Test{
    private:
        void generateData(int size, std::string filename);
        
    public:
        void testArray();
        void testList();
        void testHeap();
        void testRedBlackTree();
};