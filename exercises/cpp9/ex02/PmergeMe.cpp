#include "PmergeMe.hpp"

void PmergeVector::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _vector.push_back(pair);
}

void PmergeDeque::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _deque.push_back(pair);
}