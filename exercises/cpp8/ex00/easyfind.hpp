#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
int easyfind(T cont, int i){
    typename T::iterator it = std::find(cont.begin(), cont.end(), i);
    if(it != cont.end())
        std::cout << "Found " << i << "!" << std::endl;
    else
        throw std::runtime_error("Couldn't find this value");
    return 0;
}