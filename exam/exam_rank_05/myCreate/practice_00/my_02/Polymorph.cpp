#include "Polymorph.hpp"

Polymorph::Polymorph():
	ASpell("Polymorph", "turned into a critter")
{}

Polymorph::~Polymorph(){
	delete this;
}

Polymorph* Polymorph::clone(){
	Polymorph * temp = new(Polymorph)();
	return temp;
}