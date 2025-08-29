#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base
{
public:
    virtual ~Base();

    static Base * generate(void);
    static void identify(Base* p);
    static void identify(Base& p);
};