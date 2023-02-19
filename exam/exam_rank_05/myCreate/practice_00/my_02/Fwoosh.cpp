#include "Fwoosh.hpp"

Fwoosh::Fwoosh():
	ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::~Fwoosh(){
	delete this;
}

Fwoosh* Fwoosh::clone(){
	Fwoosh * temp = new(Fwoosh)();
	return temp;
}