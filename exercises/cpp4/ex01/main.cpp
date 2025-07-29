#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "=== Making sounds ===\n";
    for (int i = 0; i < SIZE; i++) {
        animals[i]->makeSound();
    }

    std::cout << "=== Deleting animals ===\n";
    for (int i = 0; i < SIZE; i++) {
        delete animals[i];
    }

    std::cout << "=== Deep Copy Test ===\n";
    Dog original;
    original.getBrain()->setIdea(0, "Chase the cat");

    Dog copy = original;
    original.getBrain()->setIdea(0, "Guard the house");

    std::cout << "Original idea: " << original.getBrain()->getIdea(0) << "\n";
    std::cout << "Copied idea: " << copy.getBrain()->getIdea(0) << "\n";

    return 0;
}
