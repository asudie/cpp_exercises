#include "PmergeMe.hpp"

template <template<typename, typename> class Container>
void PmergeMe<Container>::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _container.push_back(pair);
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::printContainer(){
    //std::cout << "DEBUG[PRINT1]" << std::endl;
    typename Container<pair_t, std::allocator<pair_t> >::iterator it = _container.begin();
    std::cout << "DEBUG[PRINT LOOP]" << std::endl;
    for(; it != _container.end(); it++){
        std::cout << "1[" << it->first << "]" << "2[" << it->second << "]" << std::endl;
    }
    if(_left > 0)
        std::cout << "Left[" << _left << "]" << std::endl;

}

template <template<typename, typename> class Container>
void PmergeMe<Container>::printChains(){
    typename Container<unsigned int, std::allocator<unsigned int> >::iterator it = _main.begin();
    std::cout << "MAIN" << std::endl;
    for(; it != _main.end(); it++)
       std::cout << *it << std::endl;
    std::cout << "PEND" << std::endl;
    it = _pend.begin();
    for(; it != _pend.end(); it++)
       std::cout << *it << std::endl;
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::formChains(){
    typename Container<pair_t, std::allocator<pair_t> >::iterator it = _container.begin();
    for(; it != _container.end(); it++){
        _pend.push_back(it->first);
        _main.push_back(it->second);
    }
    printChains();
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::setLeft(int n){_left = n;}

template <template<typename, typename> class Container>
int PmergeMe<Container>::getLeft(){return _left;}

/*void PmergeVector::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _vector.push_back(pair);
}

void PmergeDeque::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _deque.push_back(pair);
}*/

template <template<typename, typename> class Container>
int PmergeMe<Container>::findSmallst(int n){
    unsigned int smallest = _main[n];
    int smallest_index = n;
    for(int i = n++; i < (int)_main.size(); i++){
        if(_main[i] < smallest){
            smallest = _main[i];
            smallest_index = i;
        }    
    }
    return smallest_index;
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::recursiveSort(int n){
    if(n == (int)_main.size())
        return;
    unsigned int smallest = findSmallst(n);
    int c = _main[smallest];
    _main[smallest] = _main[n];
    _main[n] = c;
    recursiveSort(n++);
}

void PmergeVector::FordJohnson(char **argv){
    std::cout << "VECTOR" << std::endl;
    setLeft(-42);
    argv++;
    while(*argv){
        unsigned int n1 = static_cast<unsigned int>(std::stoi(*argv));
        argv++;
        if(!*argv){
            setLeft(n1);
            break;
        }
        unsigned int n2 = static_cast<unsigned int>(std::stoi(*argv));
        std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
        std::pair<unsigned int, unsigned int> pair = formPair(n1, n2);
        addElmnt(pair);
        argv++;
    }
    printContainer();
    formChains();
    recursiveSort(0);
    std::cout << "Sorted main" << std::endl;
    printChains();
    //recursively sort main    Can I do it with sort function?
    //insert pending with jacobs sequence
    //insert left over
}


void PmergeDeque::FordJohnson(char **argv){
    std::cout << "DEQUE" << std::endl;
    setLeft(-42);
    argv++;
    while(*argv){
        unsigned int n1 = static_cast<unsigned int>(std::stoi(*argv));
        argv++;
        if(!*argv){
            setLeft(n1);
            break;
        }
        unsigned int n2 = static_cast<unsigned int>(std::stoi(*argv));
        std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
        std::pair<unsigned int, unsigned int> pair = formPair(n1, n2);
        addElmnt(pair);
        argv++;
    }
    printContainer();
    formChains();
    // sort _main
}

std::pair<unsigned int, unsigned int> formPair(unsigned int n1, unsigned int n2){
    std::pair<unsigned int, unsigned int> pair;
    if(n1 < n2){
        pair.first = n1;
        pair.second = n2;
    }else{
        pair.first = n2;
        pair.second = n1;
    }
    return pair;
}