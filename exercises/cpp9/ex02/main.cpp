#include "PmergeMe.hpp"

void my_algo(PmergeDeque *deque, PmergeVector *vector, char **argv){
    deque->FordJohnson(argv);
    vector->FordJohnson(argv);
}

int main(int argc, char **argv){
    if(argc > 1) {
        PmergeDeque deque;
        PmergeVector vector;
        my_algo(&deque, &vector, argv);
    } else {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    return 0;
}