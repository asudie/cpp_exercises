#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <memory>

template <template<typename, typename> class Container>
class PmergeMe{
protected:
    typedef std::pair<unsigned int, unsigned int> pair_t;
    Container<pair_t, std::allocator<pair_t> > _container;
    Container<unsigned int, std::allocator<unsigned int> > _main;
    Container<unsigned int, std::allocator<unsigned int> > _pend;
    int _left;
    // timer
public:
    //PmergeVector(){start timer}
    //void FordJohnson(char **argv);
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
    virtual void pushFront() = 0;
};

class PmergeVector : public PmergeMe<std::vector> {
private:
    //std::vector<std::pair<unsigned int, unsigned int>> _vector;
    //std::vector<unsigned int> _main;
    //std::vector<unsigned int> _pend;
    //int _left;
    // timer
public:
    //PmergeVector(){start timer}
    void FordJohnson(char **argv);
    void pushFront();
   // void parse();
    //void addElmnt(std::pair<unsigned int, unsigned int> pair);
    //void setLeft(int n);
};
class PmergeDeque : public PmergeMe<std::deque>{
private:
    /*std::deque<std::pair<unsigned int, unsigned int>> _deque;
    std::deque<unsigned int> _main;
    std::deque<unsigned int> _pend;*/
    //int _left;
    // timer
public:
    //PmergeDeque(){start timer}
    void FordJohnson(char **argv);
    void pushFront();
    /*void parse();
    void addElmnt(std::pair<unsigned int, unsigned int> pair);
    void setLeft(int n);*/
};

std::pair<unsigned int, unsigned int> formPair(unsigned int n1, unsigned int n2);