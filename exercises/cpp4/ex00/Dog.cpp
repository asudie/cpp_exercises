#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructed\n";
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assigned\n";
	if (this != &other)
		type = other.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructed\n";
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}