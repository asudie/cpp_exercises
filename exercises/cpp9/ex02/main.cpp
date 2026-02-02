#include "PmergeMe.hpp"

std::pair<unsigned int, unsigned int> formPair(unsigned int n1, unsigned int n2){
    std::pair<unsigned int, unsigned int> pair;
    if(n1 < n2)
        pair = {n1, n2};
    else
        pair = {n2, n1};
    return pair;
}

void my_algo(PmergeDeque *deque, PmergeVector *vector, char **argv){
    ////////// Move this to pairs and sort func **
    while(argv){
        // add check if it's the last element
        unsigned int n1 = std::stoi(*argv);
        argv++;
        unsigned int n2 = std::stoi(*argv);
        std::cout << "n1 = " << n1 << "n2 = " << n2 << std::endl;
        std::pair<unsigned int, unsigned int> pair = formPair(n1, n2);
        deque->addElmnt(pair);
        vector->addElmnt(pair);
        argv++;
    }
    //////////********************************** **/


}

int main(int argc, char **argv){
    if(argc > 1) {
        PmergeDeque deque;
        PmergeVector vector;
        // start timer for both
        my_algo(&deque, &vector, argv);
    } else {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 1;
    }
    return 0;

}