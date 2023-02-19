#include "Dummy.hpp"

Dummy::Dummy():
	ATarget("Target Practice Dummy") {}

Dummy::~Dummy(){
}

Dummy* Dummy::clone(){
	Dummy * temp = new(Dummy)();
	return temp;
}