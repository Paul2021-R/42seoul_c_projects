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
	learnedMySpell.learnSpell(spell);
}
void Warlock::forgetSpell(std::string spellName) {
	learnedMySpell.forgetSpell(spellName);
}
void Warlock::launchSpell(std::string spellName, ATarget& target) {
	if (learnedMySpell.isEmpty())
		return ;
	ASpell * temp;
	temp = learnedMySpell.createSpell(spellName);
	if (temp == NULL)
		return ;
	else
		temp->launch(target);
}