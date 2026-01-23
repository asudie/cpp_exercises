#include "RPN.hpp"

int Rpn::calculate(){

}

int Rpn::parse(char *str){
    std::string ops = "+-/*";

    while(*str){
        if(isdigit(*str))
            _stack.push(*str - '0');
        if(ops.find(*str, 0) != std::string::npos)
            // send it to calculate

        str++;
    }
}