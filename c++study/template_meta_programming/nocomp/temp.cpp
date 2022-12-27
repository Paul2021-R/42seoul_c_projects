#include <iostream>

template <int X, int Y>
struct GCD {
  static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
  static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
 private:
  const static int _gcd = GCD<N, D>::value;

 public:
  typedef Ratio<N / _gcd, D / _gcd> type;
  static const int num = N / _gcd;
  static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add {
  using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
  using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
  using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
  using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V, typename W>
struct Dim {
  using M = U;
  using L = V;
  using T = W;

  using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
  typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
              typename Ratio_add<typename U::L, typename V::L>::type,
              typename Ratio_add<typename U::T, typename V::T>::type>
      type;
};

template <typename U, typename V>
struct subtract_dim_ {
  typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
              typename Ratio_subtract<typename U::L, typename V::L>::type,
              typename Ratio_subtract<typename U::T, typename V::T>::type>
      type;
};

template <typename T, typename D>
struct quantity {
  T q;
  using dim_type = D;

  quantity operator+(quantity<T, D> quant) {
    return quantity<T, D>(q + quant.q);
  }

  quantity operator-(quantity<T, D> quant) {
    return quantity<T, D>(q - quant.q);
  }

  quantity(T q) : q(q) {}
};
int main() {
  using one = Ratio<1, 1>;
  using zero = Ratio<0, 1>;

  quantity<double, Dim<one, zero, zero>> kg(1);
  quantity<double, Dim<zero, one, zero>> meter(1);
  quantity<double, Dim<zero, zero, one>> second(1);

  // Good
  kg + kg;

  // Bad
  kg + meter;
}