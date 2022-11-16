#include <iostream>

template<int X, int Y>
struct GCD{
	static const int value = GCD<Y, X % Y>::value;
	};

template <int X>
struct GCD<X, 0> {
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
	typedef Ratio<N, D> type; // this 와 비슷하게 자기 자신을 넣어주는 역할을 한다. 
	static const int num = N; // 분자
	static const int den = D; // 분모
};

template <class R1, class R2>
struct _Ratio_add {
	typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type; // 기약분수로 만들어주고, 이를 type 이라는 이름으로 나타낸다. 
};

//::type 이라고 치는 것 조차 수정하는 방법이 다음과 같다. 

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

// c++ 98
// int main() {
// 	typedef Ratio<2, 3> rat;
// 	typedef Ratio<3, 2> rat2;
// 	typedef Ratio_add<rat, rat2> rat3;

// 	std::cout << rat3::num << " / " << rat3::den << std::endl;
	
// 	return 0;
// }

// c++11
int main() {
	using rat = Ratio<2, 3>;
	using rat2 = Ratio<3, 2>;

	using rat3 = Ratio_add<rat, rat2>;
	std::cout << rat3::num << " / " << rat3::den << std::endl;

	return 0;
}