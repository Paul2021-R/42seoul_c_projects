// example 17.1 foo.h
#ifndef FOO_H
#define FOO_H

class Foo {
public:
	Foo(int i = 0);
	virtual ~Foo();
	Foo(Foo& rhs);
	Foo& operator=(Foo& rhs);
	int getVal();
	void setVal(int i);
private:
	int* iptr;
};
#endif
