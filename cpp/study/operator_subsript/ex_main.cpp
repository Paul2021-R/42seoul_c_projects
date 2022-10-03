#include "mystring.hpp"

int main(void) {
	MyString str("abcdef");
	str[3] = 'c';

	str.printnl();
}
