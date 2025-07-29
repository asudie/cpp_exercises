#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructed\n";
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assigned\n";
	if (this != &other)
		type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructed\n";
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}