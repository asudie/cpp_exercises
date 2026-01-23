#pragma once

#include <stack>
#include <iostream>
#include <string>

class Rpn{
private:
    std::stack<char> _stack;
public:
    int calculate();
    int parse(char *str);
};