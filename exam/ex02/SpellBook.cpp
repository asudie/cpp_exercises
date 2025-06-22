#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook(){
	std::map<std::string, ASpell*>::iterator it;
	for(it = spells.begin(); it != spells.end(); ++it)
		delete it->second;
}

void SpellBook::learnSpell(ASpell *spell){
	if(spell)
		spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string& name){
	std::map<std::string, ASpell*>::iterator it = spells.find(name);
	if(it != spells.end()){
		delete it->second;
		spells.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &name){
	std::map<std::string, ASpell*>::iterator it = spells.find(name);
	if(it != spells.end())
		return spells[name];
	return NULL;
}