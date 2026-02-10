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
    recursiveSort(n + 1);
}

template <template<typename, typename> class Container>
int PmergeMe<Container>::findSmallstCont(int n){ // changed to cont
    // std::cout << "FIND SM CONT 1" << std::endl;
    unsigned int smallest = _container[n].second;
    // std::cout << "FIND SM CONT 2" << std::endl;
    int smallest_index = n;
    // std::cout << "FIND SM CONT 3" << std::endl;
    for(int i = n++; i < (int)_container.size(); i++){
        if(_container[i].second < smallest){
            smallest = _container[i].second;
            smallest_index = i;
        }    
    }
    // std::cout << "FIND SM CONT 4" << std::endl;
    return smallest_index;
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::recursiveSortCont(int n){ // CHANGE TO CONT!
    if(n == (int)_container.size())
        return;
    // std::cout << "SORT CONT 1" << std::endl;
    unsigned int smallest = findSmallstCont(n);
    // std::cout << "SORT CONT 2" << std::endl;
    std::pair<int, int> c = _container[smallest]; // poiner to element in container
    // std::cout << "SORT CONT 3" << std::endl;
    _container[smallest] = _container[n];
    // std::cout << "SORT CONT 4" << std::endl;
    _container[n] = c;
    // std::cout << "SORT CONT 5" << std::endl;
    recursiveSortCont(n + 1);
}

template <template<typename, typename> class Container>
std::deque<int> PmergeMe<Container>::genJacobs(){
    std::deque<int> res;
    res.push_back(0);
    res.push_back(1);
    for(int i = 0; i < (int)_pend.size(); i++){
        res.push_back(_pend[i - 1] + 2 * _pend[i - 2]);
    }
    res.pop_front();
    res.pop_front();

    // DEBUG ****
    std::deque<int>::iterator it = res.begin();
    std::cout << "SEQUENCE" << std::endl;
    for(; it != res.end(); it++)
       std::cout << *it << std::endl;
    // DEBUG ****

    return res;
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::putElm(int n, int index){
    Container<int>::iterator it = _main.begin() + index;
    for(; it != seq.begin(); it--){
       if(n < *it && n > *(it - 1)){ // check if it works
           int tmp = *it;
           int tmp2;
           it = n;
            while(it != _main.end()){
                tmp2 = *(it + 1);
                it++;
                it = tmp;
                tmp = tmp2;
            }
            _main.push_back(tmp);
            return;
       }
    }
    // putFirst(); make it differ for deque cuz push front
}


template <template<typename, typename> class Container>
void PmergeMe<Container>::insertJacobs(){
    std::deque<int> seq = genJacobs();

    std::deque<int>::iterator it = seq.begin() + 1;
    for(; it != seq.end(); it++){
       putElm(_pend[*it], *it); 
    }

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
    recursiveSortCont(0);
    // then form chains
    printContainer();
    formChains();
    // std::cout << "Reqursively sort vector!" << std::endl;
    // recursiveSort(0);
    // std::cout << "Sorted main" << std::endl;
    printChains();
    insertJacobs();
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
    recursiveSortCont(0);
    // then form chains
    printContainer();
    formChains();
    // std::cout << "Reqursively sort vector!" << std::endl;
    // recursiveSort(0);
    // std::cout << "Sorted main" << std::endl;
    printChains();
    insertJacobs();
    //insert pending with jacobs sequence
    //insert left over
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