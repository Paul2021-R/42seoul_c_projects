#ifndef ASpell_hpp
#define ASpell_hpp

#include <iostream>
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell {
 private:
  std::string name_;
  std::string effects_;

  //   ASpell();
  //   ASpell(const ASpell& other);
  //   ASpell& operator=(const ASpell& other);
  // 딱히 컴파일이 되면 안된다는 소리 없었음. 따라서 private 지시자에 포함될
  // 필요 없음.

 public:
  ASpell();
  ASpell(const ASpell& other);
  ASpell& operator=(const ASpell& other);
  ASpell(const std::string& name, const std::string& effects);
  virtual ~ASpell();  // 순수 가상이 아니라 가상 함수이므로 상관 없음

  const std::string& getName() const;
  const std::string& getEffects() const;

  virtual ASpell* clone() const = 0;
  void launch(const ATarget& target) const;
};

#endif
