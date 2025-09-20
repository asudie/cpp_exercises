#include "easyfind.hpp"
#include <vector>

int main(){
    int arr[] = {1, 2, 3, 4, 5};
     std::vector<int> v(arr, arr + 5);
    try{
        easyfind(v, 5)
    }
    catch(std::exception &e){
        std::cout << what.e
    }
    if(!easyfind(v, 5))
        std::cout << "Found it!" << std::endl;
    else
        std::cout << "Couldn't find it!" << std::endl;

    if(!easyfind(v, 7))
        std::cout << "Found it!" << std::endl;
    else
        std::cout << "Couldn't find it!" << std::endl;
    
    return 0;
}