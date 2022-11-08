#include <iostream>

int foo() noexcept {}

int bar() noexcept { throw 1; }

int main() {
  foo();
  try {
    bar();
  } catch (int x) {
    std::cout << "Error : " << x << std::endl;
  }
}