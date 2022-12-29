#include "TargetGenerator.hpp"

typedef ATarget AT;

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	this->learned.clear();
}

void TargetGenerator::learnTargetType(ATarget * target) {
	if (target == NULL)
		return;
	for (std::vector<AT*>::iterator it = learned.begin(); it != learned.end(); ++it) {
		ATarget* temp = *it.base();
		if (!temp->getType().compare(target->getType())) {
			return ;
		}
	}
	learned.push_back(target->clone());
	return ;
}

void TargetGenerator::forgetTargetType(std::string const & type) {
	for (std::vector<AT*>::iterator it = learned.begin(); it != learned.end(); ++it) {
		ATarget* temp = *it.base();
		if (!temp->getType().compare(type)) {
			learned.erase(it);
			return ;
		}
	}
	return ;
}

AT* TargetGenerator::createTarget(std::string const & type) {
	for (std::vector<AT*>::iterator it = learned.begin(); it != learned.end(); ++it) {
		ATarget* temp = *it.base();
		if (!temp->getType().compare(type)) {
			return (temp->clone());
		}
	}
	return NULL;
}