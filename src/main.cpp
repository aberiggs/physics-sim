#include <iostream>
#include "orbital-sim/simulator.h"


int main() {
    std::cout << "Starting simulator...\n";
    Simulator simulator {};
    simulator.run();

    return 0;    
}