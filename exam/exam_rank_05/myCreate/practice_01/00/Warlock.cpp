#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
    : name(name), title(title) {
  SOUT << name << ": This looks like another boring day." << SEND;
  return;
}

Warlock::~Warlock() {
  SOUT << name << ": My job here is done!" << SEND;
  return;
}

const std::string& Warlock::getName() const { return (this->name); }
const std::string& Warlock::getTitle() const { return (this->title); }

void Warlock::setTitle(const std::string& target) { title = target; }

void Warlock::introduce() const {
  SOUT << name << ": I am " << name << ", " << title << "!" << SEND;
  return;
}