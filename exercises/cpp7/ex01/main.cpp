#include "iter.hpp"

int main()
{
    int arr1[] = {1, 2, 3, 4};
    const int arr2[] = {1, 2, 3, 4};
    std::cout << "<-----------------------------non const" << std::endl;
    iter(arr1, 4, just_print);
    std::cout << "<-----------------------------const" << std::endl;
    iter(arr2, 4, just_print);
    return 0;
}