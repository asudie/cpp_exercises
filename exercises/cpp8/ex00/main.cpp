#include "easyfind.hpp"
#include <vector>

int main(){
    std::vector<int> v = {1, 2, 3, 4, 5};
    if(!easyfind(v, 5))
        std::cout << "Found it!" << std::endl;
    else
        std::cout << "Couldn't find it!" << std::endl;
    return 0;
}