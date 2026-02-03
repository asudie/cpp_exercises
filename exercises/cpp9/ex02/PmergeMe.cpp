#include "PmergeMe.hpp"

template <template<typename T, typename ...> class Container>
void PmergeMe<Container>::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _container.push_back(pair);
}

template <template<typename T, typename ...> class Container>
void PmergeMe<Container>::printContainer(){
    std::Container<pair_t>::iterator it = data_.begin();
    for(; it != data_.end(); it++)
        std::cout << "1[" << it->first << "]" << "2[" << it->second << "]" << std::endl;
}

/*void PmergeVector::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _vector.push_back(pair);
}

void PmergeDeque::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _deque.push_back(pair);
}*/

void PmergeVector::FordJohnson(char **argv){
    while(argv){
        // add check if it's the last element
        unsigned int n1 = std::stoi(*argv);
        argv++;
        unsigned int n2 = std::stoi(*argv);
        std::cout << "n1 = " << n1 << "n2 = " << n2 << std::endl;
        std::pair<unsigned int, unsigned int> pair = formPair(n1, n2);
        addElmnt(pair);
        argv++;
    }
    printContainer();
}
void PmergeDeque::FordJohnson(char **argv){
    while(argv){
        // add check if it's the last element
        unsigned int n1 = std::stoi(*argv);
        argv++;
        unsigned int n2 = std::stoi(*argv);
        std::cout << "n1 = " << n1 << "n2 = " << n2 << std::endl;
        std::pair<unsigned int, unsigned int> pair = formPair(n1, n2);
        addElmnt(pair);
        argv++;
    }
}

std::pair<unsigned int, unsigned int> formPair(unsigned int n1, unsigned int n2){
    std::pair<unsigned int, unsigned int> pair;
    if(n1 < n2)
        pair = {n1, n2};
    else
        pair = {n2, n1};
    return pair;
}