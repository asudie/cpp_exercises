#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
int easyfind(T cont, int i){
    T<int>::iterator it = std::find(cont.begin, cont.end, i);
    if(it != cont.end)
    {
        std::cout << "Found " << i << "!" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Couldn't find " << i << "!" << std::endl;
        return 1;
    }

}