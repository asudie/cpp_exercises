#pragma once

#include <stack>
#include <iostream>
#include <string>

class Rpn{
private:
    std::stack<int> _stack;
public:
// add orthodox
    int calculate(int n1, int n2, char op);
    void parse(char *str);
};