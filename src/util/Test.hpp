#pragma once
#include <string>


class Test{
    private:

        int size = 2000;
        double time = 0.0;

    public:
        void generateData(int size, std::string filename);
        
        void testArray();
        void testList();
        void testHeap();
        void testRedBlackTree();
};