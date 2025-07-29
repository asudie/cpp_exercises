#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();
    // AAnimal animal;

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}