#include "Array.hpp"

int main()
{
    Array<int> a1;
    std::cout << "A1 size is " << a1.size() << std::endl;
    Array<double> a2(7);
    std::cout << "A2 size is " << a2.size() << std::endl;
    Array<double> a3(a2);
    return 0;
}