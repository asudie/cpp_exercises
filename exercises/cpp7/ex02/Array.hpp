#pragma once

#include <iostream>

 template<typename T>
 class Array
{
private:
    T* data_;
    unsigned int size_;
public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(const Array &other);
   // Array &operator=(const Arras &other);
  //  Array *operator[](int index);
    unsigned int size();
};

#include "Array.tpp"
