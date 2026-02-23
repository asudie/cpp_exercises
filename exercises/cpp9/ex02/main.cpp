#include "PmergeMe.hpp"

void printArgv(char **argv){
    std::cout << "Before: ";
    for(int i = 1; argv[i]; i++){
        std::cout << argv[i]   << " ";
        if(i == 10)
        {
            std::cout << "[...] ";
            break;
        }
    } 
    std::cout << std::endl;
}

void my_algo(PmergeDeque *deque, PmergeVector *vector, char **argv){
    printArgv(argv);
    deque->FordJohnson(argv);
    vector->FordJohnson(argv);
    //deque->finalPrint();
    deque->timerPrint();
    vector->timerPrint();
}

int main(int argc, char **argv){
    if(argc > 2) {
        PmergeDeque deque;
        PmergeVector vector;
        my_algo(&deque, &vector, argv);
    } else {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    return 0;
}
