#include "easyfind.hpp"
#include <vector>

int main(){
    int arr[] = {1, 2, 3, 4, 5};
     std::vector<int> v(arr, arr + 5);
    try{
        easyfind(v, 5);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        easyfind(v, 7);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}