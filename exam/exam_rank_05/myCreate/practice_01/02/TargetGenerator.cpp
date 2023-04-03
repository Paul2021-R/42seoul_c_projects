
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
  ssize_t limit = target_list.size();
  for (ssize_t i = 0; i < limit; i++) {
    std::map<std::string, ATarget*>::iterator it = target_list.begin();
    delete it.operator->()->second;
    target_list.erase(it.operator->()->first);
  }
  target_list.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
  if (target == NULL) return;
  if (target_list.find(target->getType()) == target_list.end()) {
    target_list.insert(
        std::pair<std::string, ATarget*>(target->getType(), target->clone()));
  }
  return;
}

void TargetGenerator::forgetTargetType(const std::string& target_name) {
  std::map<std::string, ATarget*>::iterator it = target_list.find(target_name);

  if (it != target_list.end()) {
    delete it.operator->()->second;
    target_list.erase(target_name);
  }
  return;
}

ATarget* TargetGenerator::createTarget(const std::string& target_name) {
  std::map<std::string, ATarget*>::iterator it = target_list.find(target_name);
  if (it == target_list.end()) {
    return (NULL);
  }
  return (it.operator->()->second->clone());
}
