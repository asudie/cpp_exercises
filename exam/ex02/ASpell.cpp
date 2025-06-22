#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::~ASpell(){}
ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects){}
ASpell::ASpell(const ASpell& other) : name(other.name), effects(other.effects){}
ASpell& ASpell::operator=(const ASpell& other){
	name = other.name;
	effects = other.effects;
	return *this;
}
	
const std::string& ASpell::getName() const{return name;}
const std::string& ASpell::getEffects() const{return effects;}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);
}
