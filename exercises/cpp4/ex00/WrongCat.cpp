#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat constructed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructed\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assigned\n";
	if (this != &other)
		type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructed\n";
}

void WrongCat::makeSound() const {
	std::cout << "Meow?? (Wrong one)\n";
}