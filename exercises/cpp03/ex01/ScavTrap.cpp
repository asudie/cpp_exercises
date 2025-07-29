#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    _name = "Default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called\n";
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap Copy assignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ScavTrap " << _name << " ferociously attacks " << target
                  << ", dealing " << _attackDamage << " points of damage!\n";
        _energyPoints--;
    } else {
        std::cout << "ScavTrap " << _name << " has no energy to attack.\n";
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " has entered Gate keeper mode.\n";
}