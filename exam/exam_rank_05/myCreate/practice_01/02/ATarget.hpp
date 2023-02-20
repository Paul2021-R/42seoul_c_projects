#ifndef ATarget_hpp
#define ATarget_hpp

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget {
 private:
  std::string type_;

 public:
  ATarget();
  ATarget(const ATarget& other);
  ATarget& operator=(const ATarget& other);
  ATarget(const std::string& type);
  virtual ~ATarget();

  const std::string& getType(void) const;
  virtual ATarget* clone() const = 0;
  void getHitBySpell(const ASpell& spell) const;
};

#endif