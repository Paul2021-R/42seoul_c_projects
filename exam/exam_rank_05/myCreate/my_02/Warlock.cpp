#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : 
	name(name), 
	title(title){
	mySpell = NULL;
	OUT << name << ": This looks like another boring day." << ENDL;
}
Warlock::~Warlock() {
	OUT << name << ": My job here is done!" << ENDL;
}

const std::string& Warlock::getName() const {
	return name;
}
const std::string& Warlock::getTitle() const {
	return title;
}
void Warlock::setTitle(const std::string &val) {
	title.clear();
	title.assign(val);
}
void Warlock::introduce() const {
	OUT << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell * spell) {
	this->mySpell = spell;
}
void Warlock::forgetSpell(std::string spellName) {
	if (mySpell == NULL)
		return ;
	if (!mySpell->getName().compare(spellName))
		this->mySpell = NULL;
	else
		return ;
}
void Warlock::launchSpell(std::string spellName, ATarget& target) {
	if (mySpell == NULL)
		return ;
	if (!mySpell->getName().compare(spellName))
		mySpell->launch(target);
	else
		return ;
}