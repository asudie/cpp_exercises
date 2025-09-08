#include "FragTrap.hpp"

int main() {
    FragTrap ft1("Serena");
    ft1.attack("target A");
    ft1.takeDamage(20);
    ft1.beRepaired(15);
    ft1.highFivesGuys();

    std::cout << "\n--- Copy + Assign Test ---\n";
    FragTrap ft2(ft1);
    FragTrap ft3;
    ft3 = ft1;
    ft3.highFivesGuys();
    return 0;
}