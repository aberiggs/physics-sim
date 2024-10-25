#include <iostream>

#include "collision-sim/simulator.h"

int main() {
    std::cout << "Starting simulator...\n";
    Simulator simulator {};
    simulator.run();

    return 0;    
}
