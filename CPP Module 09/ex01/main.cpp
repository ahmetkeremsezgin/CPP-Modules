#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Usage ./RPN \"expression\"" << std::endl;
        return 1;
    }

    rpn calculator;
    if (calculator.exec(argv[1]) == 0) {
        std::cerr << "Error" << std::endl;
        return 1;    
    }

    return 0;
}