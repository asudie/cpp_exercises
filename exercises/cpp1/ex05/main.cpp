#include "Harl.hpp"

int main(){
	Harl harl;

    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}