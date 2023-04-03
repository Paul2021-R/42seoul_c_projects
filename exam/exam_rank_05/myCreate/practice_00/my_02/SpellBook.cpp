#include "SpellBook.hpp"

SpellBook::SpellBook(){
}

SpellBook::~SpellBook(){
	learned.clear();
}

void SpellBook::learnSpell(ASpell * spell){
	if (spell == NULL)
		return ;
	for (std::vector<ASpell *>::iterator it = learned.begin(); it != learned.end(); ++it) {
		ASpell* temp = *it.base();
		if (!temp->getName().compare(spell->getName())) {
			return ;
		}
	}
	learned.push_back(spell->clone());
	return ;
}

void SpellBook::forgetSpell(std::string const & name){
	for (std::vector<ASpell *>::iterator it = learned.begin(); it != learned.end(); ++it) {
		ASpell* temp = *it.base();
		if (!temp->getName().compare(name)) {
			learned.erase(it);
			return ;
		}
	}
	return ;
}

ASpell* SpellBook::createSpell(std::string const & name){
	for (std::vector<ASpell *>::iterator it = learned.begin(); it != learned.end(); ++it) {
		ASpell* temp = *it.base();
		if (!temp->getName().compare(name)) {
			return (temp->clone());
		}
	}
	return NULL;
}

bool SpellBook::isEmpty() {
	return (learned.empty());
}