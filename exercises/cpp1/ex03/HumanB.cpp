#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL){
	this->name = name;
}

void HumanB::attack() const{
	if (this->weapon)
		std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}