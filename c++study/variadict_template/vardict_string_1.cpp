#include <iostream>
#include <string>

template <typename String>
std::string StrCat(const String& s) {
  return std::string(s);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
  return std::string(s) + StrCat(strs...);
}

int main() {
  // std::string 과 const char* 을 혼합해서 사용 가능하다.
  std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
                      " ", std::string("sentence"));
}