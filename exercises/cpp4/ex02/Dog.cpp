#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Dog copy constructed\n";
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assigned\n";
	if (this != &other){
		AAnimal::operator=(other);
		delete brain;
        brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructed\n";
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}

Brain* Dog::getBrain() const {
    return brain;
}