#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

int main(){
    std::srand(std::time(NULL));
    std::cout << "Pointer <--------------------" << std::endl;
    Base::identify(Base::generate());
    std::cout << "Reference <--------------------" << std::endl;
    Base::identify(*Base::generate());
    std::cout << "Wrong <--------------------" << std::endl;
    D d;
    Base *ptr = &d;
    Base::identify(ptr);
    Base &ref = *ptr;
    Base::identify(ref);
    return 0;
}