#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if(argc > 1) {
        BitcoinExchange bit;
        bit.start(argv[1]);
    } else {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    return 0;
}