#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : 
	name(name), 
	title(title){
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