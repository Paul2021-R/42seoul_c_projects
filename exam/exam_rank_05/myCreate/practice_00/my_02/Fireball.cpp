#include "Fireball.hpp"

Fireball::Fireball():
	ASpell("Fireball", "burnt to a crisp")
{}

Fireball::~Fireball(){
	delete this;
}

Fireball* Fireball::clone(){
	Fireball * temp = new(Fireball)();
	return temp;
}