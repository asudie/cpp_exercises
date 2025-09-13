#pragma once

 template<typename T>
 class Array
{
private:
    T* data;
    unsigned int size;
public:
    Array();
    Array(unsighed int n);
    ~Array();
    Array(const Array &other);
    Array &operator=(const Arras &other);
    Array *operator[](int index);
    unsigned int size();
};

#include "Array.tpp"
