#ifndef TargetGenerator_hpp
#define TargetGenerator_hpp

#include <iostream>
#include <map>

#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"

class TargetGenerator {
 private:
  std::map<std::string, ATarget*> target_list;

  TargetGenerator(const TargetGenerator& other);
  TargetGenerator& operator=(const TargetGenerator& other);

 public:
  TargetGenerator();
  ~TargetGenerator();
  void learnTargetType(ATarget* target);
  void forgetTargetType(const std::string& target_name);
  ATarget* createTarget(const std::string& target_name);
};

#endif