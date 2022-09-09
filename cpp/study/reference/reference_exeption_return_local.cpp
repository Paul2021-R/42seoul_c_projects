#include <iostream>

int function() {
  int a = 5;
  return a;
}

int main() {
  const int& c = function();
  std::cout << "c : " << c << std::endl;
  return 0;
}
