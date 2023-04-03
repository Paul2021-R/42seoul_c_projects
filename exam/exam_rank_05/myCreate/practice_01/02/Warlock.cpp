#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
    : name(name), title(title), learnedBook() {
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

void Warlock::learnSpell(ASpell* spell) {
  //   if (learned.find(spell->getName()) != learned.end())
  //     return;
  //   else {
  //     if (spell != NULL)
  //       learned.insert(
  //           std::pair<std::string, ASpell*>(spell->getName(),
  //           spell->clone()));
  //   }
  learnedBook.learnSpell(spell);
  return;
}

void Warlock::forgetSpell(std::string spell_name) {
  //   if (learned.find(spell_name) != learned.end()) {
  //     delete learned.at(spell_name);
  //     learned.erase(spell_name);
  //     return;
  //   } else
  //     return;
  learnedBook.forgetSpell(spell_name);
}

void Warlock::launchSpell(std::string spell_name, const ATarget& target) {
  //   if (learned.find(spell_name) != learned.end()) {
  //     learned.at(spell_name)->launch(target);
  //   }
  const ATarget* test = 0;
  if (&target == test) return;
  ASpell* temp = learnedBook.createSpell(spell_name);
  if (temp) {
    temp->launch(target);
  }
  //   delete temp;
  return;
}