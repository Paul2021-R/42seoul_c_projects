#ifndef BrickWall_hpp
#define BrickWall_hpp

#include "ATarget.hpp"

class BrickWall : public ATarget {
 private:
 public:
  BrickWall();
  BrickWall(const BrickWall& other);
  ~BrickWall();
  ATarget* clone() const;
};

#endif