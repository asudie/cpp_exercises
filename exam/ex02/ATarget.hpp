#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget{
protected:
	std::string type;
	
	
public:
	ATarget();
	ATarget(std::string type);
	virtual ~ATarget();
	ATarget(const ATarget& other);
	ATarget& operator=(const ATarget& other);
	
	const 	std::string& getType() const;
	
	virtual ATarget* clone() const = 0;
	
	void getHitBySpell(const ASpell& spell) const;
};
