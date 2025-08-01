#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
    std::string name;
    std::string title;
    std::map<std::string, ASpell*> spells;

    Warlock();
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);

public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);
    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& name);
    void launchSpell(const std::string& name, const ATarget& target);
};
