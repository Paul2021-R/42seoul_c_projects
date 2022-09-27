#include "mystring.hpp"
#include <string>

int main(void) {
	//explicit 키워드 사용 예시

	//DoSomethingwithString(3);
	DoSomethingwithString(MyString(3));

	MyString s(5); // 허용
	//MyString r = 5; // 컴파일 오류!

	//mutable 키워드 사용 예시
}
