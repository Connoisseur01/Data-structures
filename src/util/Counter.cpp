#include "Counter.hpp"

Counter::Counter(){
    clock = std::chrono::high_resolution_clock();
}

void Counter::startCounter(){
    startPoint = clock.now();
}

void Counter::stopCounter(){
    stopPoint = clock.now();
}

double Counter::getCounter(){
    std::chrono::duration<double, std::milli> duration = stopPoint - startPoint;
    return duration.count();
}