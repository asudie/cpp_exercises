#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
#include <map>

class SpellBook{
private:
	SpellBook(const SpellBook& other);
	SpellBook& operator=(const SpellBook& other);
	std::map<std::string, ASpell*> spells;
public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string const &);
	ASpell* createSpell(std::string const &);

};