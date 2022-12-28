#include "ATarget.hpp"

ATarget::ATarget(const std::string& type): 
	type(type){}

ATarget::~ATarget() {
	delete this;
}
const std::string& ATarget::getType() const {
	return this->type;
}
ATarget* ATarget::clone() {
	ATarget* temp = new(ATarget)(getType());
	return temp;
}

void ATarget::getHitBySpell(const ASpell& spell) {
	OUT << type << " has been " << spell.getEffects() << "!" << ENDL;
}