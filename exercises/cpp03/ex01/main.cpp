#include "ScavTrap.hpp"

int main() {
    std::cout << "=== ClapTrap test ===\n";
    ClapTrap c1("CL");
    c1.attack("target1");
    c1.beRepaired(5);
    c1.takeDamage(3);

    std::cout << "\n=== ScavTrap test ===\n";
    ScavTrap s1("SC");
    s1.attack("target2");
    s1.beRepaired(10);
    s1.takeDamage(20);
    s1.guardGate();

    std::cout << "\n=== Destructor test ===\n";
    return 0;
}