#include "MutantStack.h"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "Copy contructor and const iterator!" << std::endl;
    std::stack<int> s(mstack);
    MutantStack<int>::const_iterator c_it = mstack.begin();
    MutantStack<int>::const_iterator c_ite = mstack.end();
    while (c_it != c_ite)
    {
        std::cout << *c_it << std::endl;
        ++c_it;
    }
    std::cout << "Reversed iterator!" << std::endl;
    MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
    MutantStack<int>::reverse_iterator r_ite = mstack.rend();
    while (r_it != r_ite)
    {
        std::cout << *r_it << std::endl;
        ++r_it;
    }

    std::cout << "Const reversed iterator!" << std::endl;
    MutantStack<int>::const_reverse_iterator cr_it = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator cr_ite = mstack.rend();
    while (cr_it != cr_ite)
    {
        std::cout << *cr_it << std::endl;
        ++cr_it;
    }
    return 0;
}