#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"


class Fwoosh : public ASpell{
	
public:
	Fwoosh();
	virtual ~Fwoosh();	
	virtual Fwoosh* clone() const;
};
