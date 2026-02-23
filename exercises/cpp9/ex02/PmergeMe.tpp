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

/*template <template<typename, typename> class Container>
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
} */

//template <template<typename, typename> class Container>
//void PmergeMe<Container>::recursiveSortCont(int n){
//    (void)n;
//    recursiveSortCont(_container);
//}

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
void PmergeMe<Container>::timerPrint(){
    double duration = static_cast<double>(_end - _start)
                  / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _size << " elements with std::" << _name << " : " << duration << " us" << std::endl;
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::finalPrint(){
    //printContainer();
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
}

unsigned int safeStoi(const char* str)
{
    try
    {
        int value = std::atoi(str);

        if (value < 0)
            throw std::invalid_argument("negative");

        return static_cast<unsigned int>(value);
    }
    catch (...)
    {
        std::cout << "Error: wrong numbers!" << std::endl;
        exit(1);
    }
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::parseArgs(char **argv){
    std::vector<unsigned int>tmp;
    _size = 0;
    argv++;
    while(*argv){
        unsigned int n1 = safeStoi(*argv);
        if(std::find(tmp.begin(), tmp.end(), n1) != tmp.end()){
            std::cout << "Error: duplicate found!" << std::endl;
            exit(1);
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
            exit(1);
        }
        tmp.push_back(n2);
        _size++;
        std::pair<unsigned int, unsigned int> pair = formPair(n1, n2);
        addElmnt(pair);
        argv++;
    }
    // printContainer();
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::startTimer(){
    _start = clock();
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::stopTimer(){
    _end = clock();
}

void PmergeVector::setName(){
    _name = "vector";
}

void PmergeDeque::setName(){
    _name = "deque";
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::insertPendIntoWinners(Container<pair_t, std::allocator<pair_t> >& winners, Container<pair_t, std::allocator<pair_t> >& pend){
    if (pend.empty()) return;
    typename Container<pair_t, std::allocator<pair_t> >::iterator pos;
    int left, right, mid;
    winners.insert(winners.begin(), pend[0]);
    std::deque<int> seq = genJacobs(static_cast<int>(pend.size()));
    for (size_t k = 0; k < seq.size(); k++) {
        int curr = seq[k];
        if (curr >= (int)pend.size()) break;
        const pair_t& p = pend[curr];
        left = 0;
        right = static_cast<int>(winners.size());
        while (left < right) {
            mid = left + (right - left) / 2;
            if (winners[mid].second < p.second)
                left = mid + 1;
            else
                right = mid;
        }
        pos = winners.begin() + left;
        winners.insert(pos, p);
        // pend.erase(curr);
        int prev = (k == 0) ? 0 : seq[k - 1];
        for (int i = curr - 1; i > prev; i--) {
            const pair_t& q = pend[i];
            left = 0;
            right = static_cast<int>(winners.size());
            while (left < right) {
                mid = left + (right - left) / 2;
                if (winners[mid].second < q.second)
                    left = mid + 1;
                else
                    right = mid;
            }
            pos = winners.begin() + left;
            winners.insert(pos, q);
        }
    }
}

template <template<typename, typename> class Container>
std::deque<int> PmergeMe<Container>::genJacobs(int size){
    std::deque<int> res;
    res.push_back(0);
    res.push_back(1);
    while (true) {
        int next = res[res.size() - 1] + 2 * res[res.size() - 2];
        res.push_back(next);
        if (next >= size) break;
    }
    res.pop_front();
    res.pop_front();
    return res;
}

template <template<typename, typename> class Container>
std::deque<int> PmergeMe<Container>::genJacobs(){
    return genJacobs(static_cast<int>(_pend.size()));
}

/*template <template<typename, typename> class Container>
void PmergeMe<Container>::recursiveSortCont(Container<pair_t, std::allocator<pair_t> >& cont){
    if (cont.size() <= 1)
        return;
    const int n = static_cast<int>(cont.size());
    for (int i = 0; i + 1 < n; i += 2) {
        if (cont[i].second > cont[i + 1].second)
            std::swap(cont[i], cont[i + 1]);
    }
    Container<pair_t, std::allocator<pair_t> > winners;
    Container<pair_t, std::allocator<pair_t> > pend;
    for (int i = 0; i + 1 < n; i += 2) {
        pend.push_back(cont[i]);
        winners.push_back(cont[i + 1]);
    }
    if (n % 2 == 1)
        pend.push_back(cont[n - 1]);
    recursiveSortCont(winners);
    insertPendIntoWinners(winners, pend);
    cont = winners;
}*/

template <template<typename, typename> class Container>
void PmergeMe<Container>::genFordJonson(Container<pair_t, std::allocator<pair_t> >& cont){
    if (cont.size() <= 1)
        return;
    const int n = static_cast<int>(cont.size());
    Container<pair_t, std::allocator<pair_t> > winners;
    Container<pair_t, std::allocator<pair_t> > pend;
    for (int i = 0; i + 1 < n; i += 2) {
        if (cont[i].second > cont[i + 1].second)
            std::swap(cont[i], cont[i + 1]);
        pend.push_back(cont[i]);
        winners.push_back(cont[i + 1]);
    }
    if (n % 2 == 1)
        pend.push_back(cont[n - 1]);
    genFordJonson(winners);
    insertPendIntoWinners(winners, pend);
    cont = winners;
}

void PmergeVector::FordJohnson(char **argv){
    setName();
    startTimer();
    setLeft(-42);
    parseArgs(argv);
    genFordJonson(_container);
    // printContainer();
    //recursiveSortCont(_container);
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
    genFordJonson(_container);
    // printContainer();
    /*recursiveSortCont(_container);
    formChains();
    insertJacobs();*/
    // printChains();
    stopTimer();
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
