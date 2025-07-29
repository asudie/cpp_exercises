#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Clappy");
    ClapTrap b(a);
    ClapTrap c;
    c = b;

    a.attack("Enemy");
    a.takeDamage(5);
    a.beRepaired(3);

    return 0;
}