#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock(const std::string& name, const std::string& title)
  : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!" << std::endl;

    // Delete all stored spell pointers
    std::map<std::string, ASpell*>::iterator it;
    for (it = spells.begin(); it != spells.end(); ++it)
        delete it->second;
}

const std::string& Warlock::getName() const {
    return this->name;
}

const std::string& Warlock::getTitle() const {
    return this->title;
}

void Warlock::setTitle(const std::string& title) {
    this->title = title;
}

void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string& name) {
    std::map<std::string, ASpell*>::iterator it = spells.find(name);
    if (it != spells.end()) {
        delete it->second;
        spells.erase(it);
    }
}

void Warlock::launchSpell(const std::string& name, const ATarget& target) {
    std::map<std::string, ASpell*>::const_iterator it = spells.find(name);
    if (it != spells.end())
        it->second->launch(target);
}
