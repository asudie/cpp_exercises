#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *arr, size_t len, void(*func)(T &arr))
{
    for(size_t i = 0; i < len; i++)
        func(arr[i]);
    
}

template <typename T>
void just_print(T &arr)
{
    std::cout << arr << std::endl;
}