#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <memory>
#include <chrono>

template <template<typename, typename> class Container>
class PmergeMe{
protected:
    typedef std::pair<unsigned int, unsigned int> pair_t;
    Container<pair_t, std::allocator<pair_t> > _container;
    Container<unsigned int, std::allocator<unsigned int> > _main;
    Container<unsigned int, std::allocator<unsigned int> > _pend;
    int _left;
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
    std::chrono::time_point<std::chrono::high_resolution_clock> _end;
    std::string _name;
    int _size;
public:
    PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
    void parse();
    void addElmnt(std::pair<unsigned int, unsigned int> pair);
    void setLeft(int n);
    int getLeft();
    void printContainer();
    void formChains();
    void printChains();
    void recursiveSort(int n);
    int findSmallst(int n);
    void insertJacobs();
    std::deque<int> genJacobs();
    int findSmallstCont(int n);
    void recursiveSortCont(int n);
    void putElm(int n, int index);
    void finalPrint();
    void parseArgs(char **argv);
    void startTimer();
    void stopTimer();
    virtual void pushFront(unsigned int n) = 0;
};

class PmergeVector : public PmergeMe<std::vector> {
public:
    void FordJohnson(char **argv);
    void pushFront(unsigned int n);
    void setName();
};
class PmergeDeque : public PmergeMe<std::deque>{
public:
    void FordJohnson(char **argv);
    void pushFront(unsigned int n);
    void setName();
};

std::pair<unsigned int, unsigned int> formPair(unsigned int n1, unsigned int n2);

#include "PmergeMe.tpp"

#endif