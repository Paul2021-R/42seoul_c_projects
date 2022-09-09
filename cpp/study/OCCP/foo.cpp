// 17.2 foo.cpp
#include "foo.h"

Foo::Foo(int i){ iptr = new int(i); }

Foo::~Foo() { delete iptr; }

Foo::Foo(Foo& rhs) {
	iptr = new int(*(rhs.iptr)); 
}

Foo& Foo::operator=(Foo& rhs){
	*iptr = *(rhs.iptr);
	return *this;
}

int Foo::getVal(){ return *iptr; }

void Foo::setVal(int i){ *iptr = i; }
