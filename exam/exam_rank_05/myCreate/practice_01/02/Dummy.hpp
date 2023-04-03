#ifndef Dummy_hpp
#define Dummy_hpp

#include "ATarget.hpp"

class Dummy : public ATarget {
 private:
 public:
  Dummy();
  Dummy(const Dummy& other);
  ~Dummy();
  ATarget* clone() const;
};

#endif