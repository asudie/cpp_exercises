#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>


int main(){
    Data obj;
    uintptr_t raw = Serializer::serialize(&obj);
    std::cout << "Serialized data " << &obj << " = " << raw << std::endl;
    Data *back = Serializer::deserialize(raw);

    if(back == &obj)
        std::cout << "Success" << std::endl;
    else
        std::cout << "Fail" << std::endl;

}