#pragma once
#include <iostream>
#include <string>
#include "ATarget.hpp"


class BrickWall : public ATarget{
	
public:
	BrickWall();
	virtual ~BrickWall();	
	virtual BrickWall* clone() const;
};
