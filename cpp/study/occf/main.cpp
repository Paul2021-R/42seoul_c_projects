// 17.3 main.cpp
#include <iostream>
#include "foo.h"
#include "f.h"

using namespace std;

int main(){

	Foo f0, f1(1), f2(2);
	cout << "initial f0 : default : " << f0.getVal() << endl;
	cout << "initial f1 : 1 : " << f1.getVal() << endl;
	cout << "initial f2 : 2 : "  << f2.getVal() << endl;
	cout << "--------------" << endl;

	Foo f3(f2);
	cout << "f3(f2) : "  <<f3.getVal() << endl;
	f3 = f1;
	cout << "f3 = f1 : " << f3.getVal() << endl;
	cout << "--------------" << endl;

	f3.setVal(3);
	cout << "f3.setVal(3) : " << f0.getVal() << endl;
	cout << "f1 getval : " << f1.getVal() << endl;
	cout << "f2 getval : " << f2.getVal() << endl;
	cout << "f3 getval : " << f3.getVal() << endl;
	cout << "--------------" << endl;
	
	f3 = fooFunction(f2);
	cout << "f3 = fooFunction(f2) : " << f3.getVal() << endl;
	return (0);
}
