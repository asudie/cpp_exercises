#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

Base::~Base(){}
Base * Base::generate(void){
    std::cout << "Generating..." << std::endl;
    int try1 = std::rand();
    int try2 = std::rand();
    if(try1 % 2 == 0 && try2 % 2 != 0)
    {
        std::cout << "A!" << std::endl;
        return new A();
    }
    else if (try1 % 2 != 0 && try2 % 2 == 0)
    {
        std::cout << "B!" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "C!" << std::endl;
        return new C();
    }
}
    void Base::identify(Base* p){
        std::cout << "Identifying pointer..." << std::endl;
        if(dynamic_cast<A*>(p))
            std::cout << "Pointer identifies as A!" << std::endl;
        else if(dynamic_cast<B*>(p))
            std::cout << "Pointer identifies as B!" << std::endl;
        else if(dynamic_cast<C*>(p))
            std::cout << "Pointer identifies as C!" << std::endl;
        else
            std::cout << "Unknown type!" << std::endl;
    }

    void Base::identify(Base& p){
        std::cout << "Identifying reference..." << std::endl;
        try{
            dynamic_cast<A&>(p);
            std::cout << "Pointer identifies as A!" << std::endl;
            return;

        } catch(...){}
        try{
            dynamic_cast<B&>(p);
            std::cout << "Pointer identifies as B!" << std::endl;
            return;

        } catch(...){}
        try{
            dynamic_cast<C&>(p);
            std::cout << "Pointer identifies as C!" << std::endl;
            return;

        } catch(...){}
        std::cout << "Unknown type!" << std::endl;
    }