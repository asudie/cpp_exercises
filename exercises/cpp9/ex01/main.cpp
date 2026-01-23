#include "RPN.hpp"

int main(int argc, char **argv){
    if(argc != 2)
        std::cout << "Usage: ./RPN \"POLISH NOTATION\"" << std::endl;
    else {
        Rpn x;
        x.parse(argv[1]);
        x.calculate();
    }
    return 0;
}