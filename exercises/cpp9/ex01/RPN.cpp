#include "RPN.hpp"

Rpn::Rpn(){}

Rpn::Rpn(const Rpn &other){
	*this = other;
}

Rpn &Rpn::operator=(const Rpn &other){
	if(this != &other)
		this->_stack = other._stack;
	return *this;
}

Rpn::~Rpn(){}

int Rpn::calculate(int n1, int n2, char op){
    switch(op){
        case '+':
            _stack.push(n2 + n1);
            return 1;
        case '-':
            _stack.push(n2 - n1);
            return 1;
        case '*':
            _stack.push(n2 * n1);
            return 1;
        case '/':
            _stack.push(n2 / n1);
            return 1;
        default:
            return 0;
    }
}

void Rpn::parse(char *str){
    std::string ops = "+-/*";

    while(*str){
        //std::cout << "str = " << *str << std::endl;
        if(isdigit(*str)){
            _stack.push(*str - '0');
            //std::cout << "Pushed " << *str - '0' << std::endl;
        }else if(ops.find(*str, 0) != std::string::npos)
        {
            int n1 = _stack.top();
            _stack.pop();
            int n2 = _stack.top();
            _stack.pop();

            calculate(n1, n2, *str);
        } else if(*str != ' '){
            std::cout << "Error!" << std::endl;
            return;
        }
        str++;
    }
    std::cout << _stack.top() << std::endl;

}