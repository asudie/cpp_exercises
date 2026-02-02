#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <string>

class PmergeVector{
private:
    std::vector<std::pair<unsigned int, unsigned int>> _vector;
    std::vector<unsigned int> _main;
    std::vector<unsigned int> _pend;
    int _left;
    // timer
public:
    //PmergeVector(){start timer}
    void FordJohnson();
    void parse();
    void addElmnt(std::pair<unsigned int, unsigned int> pair);
    void setLeft(int n);
};
class PmergeDeque{
private:
    std::deque<std::pair<unsigned int, unsigned int>> _deque;
    std::deque<unsigned int> _main;
    std::deque<unsigned int> _pend;
    int _left;
    // timer
public:
    //PmergeDeque(){start timer}
    void FordJohnson();
    void parse();
    void addElmnt(std::pair<unsigned int, unsigned int> pair);
    void setLeft(int n);
};