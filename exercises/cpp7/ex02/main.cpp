#include "Array.hpp"

template <typename T>
void just_print(Array<T> arr)
{
    T* data = arr.getData();
    for(unsigned int i = 0; i < arr.size(); i++)
            std::cout << data[i] << std::endl;
}

int main()
{
    Array<int> a1;
    std::cout << "A1 size is " << a1.size() << std::endl;
    Array<double> a2(7);
    std::cout << "A2 size is " << a2.size() << std::endl;
    std::cout << "<-----------------------------copy constructor" << std::endl;
    Array<double> a3(a2);
    std::cout << "A3 size is " << a3.size() << std::endl;
    just_print(a3);
    a2.setData(1, 2);
    std::cout << "<-----------------------------changed a2 and print a3" << std::endl;
    just_print(a3);
    std::cout << "<-----------------------------copy assignment" << std::endl;
    Array<double> a4;
    a4 = a2;
    std::cout << "A4 size is " << a4.size() << std::endl;
    just_print(a4);
    std::cout << "[] -  " <<  a4[0] << std::endl;
    try{
        std::cout << "[] -  " <<  a4[-1] << std::endl;
    } catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}
    return 0;
}