#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
#include "SpellBook.hpp"

class Warlock{
private:
	std::string name;
	std::string title;
	Warlock(const Warlock& other);
	Warlock& operator=(const Warlock& other);
	SpellBook book;
	
public:
	Warlock(std::string name, std::string title);
	~Warlock();
	
	const std::string& getName() const;
	const std::string& getTitle() const;
	
	void setTitle(const std::string& newTitle);
	
	void introduce() const;
	
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string name);
	void launchSpell(std::string name, ATarget& target);
};
