#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){
	std::map<std::string, ATarget*>::iterator it;
	for(it = targets.begin(); it != targets.end(); ++it)
		delete it->second;

}
void TargetGenerator::learnTargetType(ATarget* target){
	if(target)
		targets[target->getType()] = target->clone();
}
void TargetGenerator::forgetTargetType(std::string const &name){
	std::map<std::string, ATarget*>::iterator it = targets.find(name);
	if(it != targets.end()){
		delete it->second;
		targets.erase(it);
	}
}
ATarget* TargetGenerator::createTarget(std::string const &type){
	std::map<std::string, ATarget*>::iterator it = targets.find(type);
	if(it != targets.end())
		return targets[type];
	return NULL;
}