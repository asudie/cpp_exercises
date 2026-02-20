#include "PmergeMe.hpp"

template <template<typename, typename> class Container>
PmergeMe<Container>::PmergeMe(){}


template <template<typename, typename> class Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other){
	*this = other;
}

template <template<typename, typename> class Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &other){
    if (this != &other) {
        _container = other._container;
        _main = other._main;
        _pend = other._pend;
        _left = other._left;
        _start = other._start;
        _end = other._end;
        _name = other._name;
        _size = other._size;
    }
	return *this;
}

template <template<typename, typename> class Container>
PmergeMe<Container>::~PmergeMe(){}

template <template<typename, typename> class Container>
void PmergeMe<Container>::addElmnt(std::pair<unsigned int, unsigned int> pair){
    _container.push_back(pair);
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::printContainer(){
    typename Container<pair_t, std::allocator<pair_t> >::iterator it = _container.begin();
    std::cout << "Before: ";
    int i = 0;
    for(; it != _container.end(); it++){
        std::cout << it->first << " " << it->second << " ";
        if(i == 5)
        {
            std::cout << "[...] ";
            break;
        }
        i++;
    }
    if(_left > 0)
        std::cout << _left;
    std::cout << std::endl;

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
int PmergeMe<Container>::findSmallstCont(int n){
    unsigned int smallest = _container[n].second;
    int smallest_index = n;
    for(int i = n++; i < (int)_container.size(); i++){
        if(_container[i].second < smallest){
            smallest = _container[i].second;
            smallest_index = i;
        }    
    }
    return smallest_index;
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::recursiveSortCont(int n){
    if(n == (int)_container.size())
        return;
    unsigned int smallest = findSmallstCont(n);
    std::pair<int, int> c = _container[smallest];
    _container[smallest] = _container[n];
    _container[n] = c;
    recursiveSortCont(n + 1);
}

template <template<typename, typename> class Container>
std::deque<int> PmergeMe<Container>::genJacobs(){
    std::deque<int> res;

    int size = static_cast<int>(_pend.size());

    res.push_back(0);
    res.push_back(1);

    while (true)
    {
        int next = res[res.size() - 1] + 
                   2 * res[res.size() - 2];

        res.push_back(next);
        if (next >= size)
            break;
    }
    res.pop_front();
    res.pop_front();

    // DEBUG ****
    // std::deque<int>::iterator it = res.begin();
    // std::cout << "SEQUENCE" << std::endl;
    // for(; it != res.end(); it++)
    //    std::cout << *it << std::endl;
    // DEBUG ****
    return res;
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::putElm(int n, int index){
    int left = 0;
    int right = index;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (_main[mid] < static_cast<unsigned int>(n))
            left = mid + 1;
        else
            right = mid;
    }

    _main.insert(_main.begin() + left, n);
}

void PmergeVector::pushFront(unsigned int n){
    std::vector<unsigned int>::iterator it = _main.begin();
    unsigned int tmp = n;
    unsigned int tmp2;
    while(it != _main.end()){
        tmp2 = *it;
        *it = tmp;
        it++;
        tmp = *it;
        *it = tmp;
        tmp = tmp2;
    }
    _main.push_back(tmp);
    return;
}

void PmergeDeque::pushFront(unsigned int n){
    _main.push_front(n);
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::insertJacobs(){
    std::deque<int> seq = genJacobs();

    pushFront(_pend[0]);

    for (size_t k = 0; k < seq.size(); k++)
    {
        int curr = seq[k];

        if (curr >= (int)_pend.size())
            break;

        // std::cout << "DEBUG INSERT: index = "
        //           << curr
        //           << ", value = "
        //           << _pend[curr]
        //           << std::endl;

        putElm(_pend[curr], curr);

        int prev = (k == 0) ? 0 : seq[k - 1];

        for (int i = curr - 1; i > prev; i--)
        {
            // std::cout << "DEBUG INSERT: index = "
            //           << i
            //           << ", value = "
            //           << _pend[i]
            //           << std::endl;

            putElm(_pend[i], i);
        }
    }
    if(_left != -42)
        putElm(_left, _main.size());
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::finalPrint(){
    std::cout << "After: ";
    for(int i = 0; i < (int)_main.size(); i++){
        if(i == 10)
        {
            std::cout << "[...] ";
            break;
        }
        std::cout << _main[i] << " ";
    }
    std::cout << std::endl;
    std::chrono::duration<double, std::micro> duration = _end - _start;
    std::cout << "Time to process a range of " << _size << " elements with std::" << _name << " : " << duration.count() << " us" << std::endl;
}

unsigned int safeStoi(const char* str)
{
    try
    {
        int value = std::stoi(str);

        if (value < 0)
            throw std::invalid_argument("negative");

        return static_cast<unsigned int>(value);
    }
    catch (...)
    {
        std::cout << "Error: wrong numbers!" << std::endl;
        std::exit(1);
    }
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::parseArgs(char **argv){
    std::vector<unsigned int>tmp;
    _size = 0;
    argv++; // TODO: make it orthodox
    while(*argv){
        unsigned int n1 = safeStoi(*argv);
        if(std::find(tmp.begin(), tmp.end(), n1) != tmp.end()){
            std::cout << "Error: duplicate found!" << std::endl;
            std::exit(1);
        }
        tmp.push_back(n1);
        _size++;
        argv++;
        if(!*argv){
            setLeft(n1);
            break;
        }
        unsigned int n2 = safeStoi(*argv);
        if(std::find(tmp.begin(), tmp.end(), n2) != tmp.end()){
            std::cout << "Error: duplicate found!" << std::endl;
            std::exit(1);
        }
        tmp.push_back(n2);
        _size++;
        std::pair<unsigned int, unsigned int> pair = formPair(n1, n2);
        addElmnt(pair);
        argv++;
    }
    printContainer();
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::startTimer(){
    _start = std::chrono::high_resolution_clock::now();
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::stopTimer(){
    _end = std::chrono::high_resolution_clock::now();
}

void PmergeVector::setName(){
    _name = "vector";
}

void PmergeDeque::setName(){
    _name = "deque";
}

void PmergeVector::FordJohnson(char **argv){
    setName();
    startTimer();
    setLeft(-42);
    parseArgs(argv);
    // printContainer();
    recursiveSortCont(0);
    formChains();
    insertJacobs();
    // printChains();
    stopTimer();
    finalPrint();
}


void PmergeDeque::FordJohnson(char **argv){
    setName();
    startTimer();
    setLeft(-42);
    parseArgs(argv);
    // printContainer();
    recursiveSortCont(0);
    formChains();
    insertJacobs();
    // printChains();
    stopTimer();
    finalPrint();
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