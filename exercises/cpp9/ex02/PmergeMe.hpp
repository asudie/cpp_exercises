#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <string>

template <template<typename T, typename ...> class Container>
class PmergeMe{
private:
    using pair_t = std::pair<unsigned int, unsigned int>;
    Container<pair_t> _container;
    std::vector<unsigned int> _main;
    std::vector<unsigned int> _pend;
    int _left;
    // timer
public:
    //PmergeVector(){start timer}
    //void FordJohnson(char **argv);
    void parse();
    void addElmnt(std::pair<unsigned int, unsigned int> pair);
    // void setLeft(int n);
    void printContainer();
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
   // void parse();
    //void addElmnt(std::pair<unsigned int, unsigned int> pair);
    //void setLeft(int n);
};
class PmergeDeque : public PmergeMe<std::deque>{
private:
    /*std::deque<std::pair<unsigned int, unsigned int>> _deque;
    std::deque<unsigned int> _main;
    std::deque<unsigned int> _pend;*/
    int _left;
    // timer
public:
    //PmergeDeque(){start timer}
    void FordJohnson(char **argv);
    /*void parse();
    void addElmnt(std::pair<unsigned int, unsigned int> pair);
    void setLeft(int n);*/
};

std::pair<unsigned int, unsigned int> formPair(unsigned int n1, unsigned int n2);