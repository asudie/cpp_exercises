#include "PmergeMe.hpp"

void my_algo(PmergeDeque *deque, PmergeVector *vector, char **argv){
    //std::cout << "DEBUG[6]" << std::endl;
    deque->FordJohnson(argv);
    //std::cout << "DEBUG[7]" << std::endl;
    vector->FordJohnson(argv);
    //std::cout << "DEBUG[7]" << std::endl;
}

int main(int argc, char **argv){
    if(argc > 1) {
        //std::cout << "DEBUG[1]" << std::endl;
        PmergeDeque deque;
       // std::cout << "DEBUG[2]" << std::endl;
        PmergeVector vector;
       // std::cout << "DEBUG[4]" << std::endl;
        // start timer for both
        my_algo(&deque, &vector, argv);
        std::cout << "DEBUG[5]" << std::endl;
    } else {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    return 0;
}