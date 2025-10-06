#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
private:
        <T> first_;
public:
    std::begin(){return first_};
    end(){return this->top;};
};