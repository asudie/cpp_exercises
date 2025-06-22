#pragma once
#include <iostream>
#include <string>
#include "ATarget.hpp"
#include <map>

class TargetGenerator{
private:
	std::map<std::string, ATarget*> targets;
	TargetGenerator(const TargetGenerator& other);
	TargetGenerator& operator=(const TargetGenerator& other);

public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const &name);
	ATarget* createTarget(std::string const &);
};