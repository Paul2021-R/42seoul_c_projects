// 17.5 f.cpp
#include "f.h"
#include "foo.h"
#include <iostream>
using namespace std;

Foo& fooFunction(Foo foo){
	cout << "fooFunction() called: " << foo.getVal() << endl;
	return foo;
}
