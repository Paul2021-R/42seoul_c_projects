#ifndef Warlock_hpp
#define Warlock_hpp

#include <iostream>
#include <map>
#include <string>

#include "Dummy.hpp"
#include "Fwoosh.hpp"

#define SOUT std::cout
#define SEND std::endl;

class Warlock {
 private:
  std::string name;
  std::string title;
  std::map<std::string, ASpell*> learned;

  Warlock();
  Warlock(const Warlock& other);
  Warlock& operator=(const Warlock& other);

 public:
  Warlock(const std::string& name, const std::string& title);
  ~Warlock();
  const std::string& getName() const;
  const std::string& getTitle() const;

  void setTitle(const std::string& target);
  void introduce() const;
  void learnSpell(ASpell* spell);
  void forgetSpell(std::string spell_name);
  void launchSpell(std::string spell_name, const ATarget& target);
};

#endif