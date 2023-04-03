#ifndef TARGETGENERATOR_HPP_
#define TARGETGENERATOR_HPP_

#include <vector>
#include <string>
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"

typedef ATarget AT;

class TargetGenerator {
private:
std::vector<AT*> learned;
TargetGenerator(const TargetGenerator& other);
TargetGenerator& operator=(const TargetGenerator& other) const;

public:
TargetGenerator();
~TargetGenerator();
void learnTargetType(ATarget * target);
void forgetTargetType(std::string const & type);
AT* createTarget(std::string const & type);
};

#endif