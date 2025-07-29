#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie() {
    std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::setName(std::string newName){
	name = newName;
}

void Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}