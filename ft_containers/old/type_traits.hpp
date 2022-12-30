/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:57:53 by haryu             #+#    #+#             */
/*   Updated: 2022/12/16 23:52:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef type_traits_hpp
# define type_traits_hpp

#define FT_NOEXCEPT throw()

namespace ft{

template <typename T, T v>
struct integral_constant {
	typedef integral_constant<T, v> type;
	typedef T value_type;
	static const T value = v;
	operator value_type() const FT_NOEXCEPT { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <bool, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
	typedef T type;
};

template <typename T>
struct _remove_cv {
	typedef T type;
};

template <typename T>
struct _remove_cv<const T> {
	typedef T type;
};

template <typename T>
struct _remove_cv<volatile T> {
	typedef T type;
};

template <typename T>
struct _remove_cv<const volatile T> {
	typedef T type;
};

template <typename T>
struct remove_cv {
	typedef typename _remove_cv<T>::type type;
};

/**
 * @brief enable_if 구현체, SFINAE 를 활용하여 우선순위를 지정하고 false 와 true 를 구현함. 지정된 값은 true_type으로 지정해버리게 된다. 
 * 
 * @tparam T 
 */
template<typename T>
struct _is_integral : public false_type {};
template <>
struct _is_integral<bool> : public true_type {};
template <>
struct _is_integral<char> : public true_type {};
template <>
struct _is_integral<unsigned char> : public true_type {};
template <>
struct _is_integral<signed char> : public true_type {};
template <>
struct _is_integral<wchar_t> : public true_type {};
template <>
struct _is_integral<short> : public true_type {};
template <>
struct _is_integral<unsigned short> : public true_type {};
template <>
struct _is_integral<int> : public true_type {};
template <>
struct _is_integral<unsigned int> : public true_type {};
template <>
struct _is_integral<long> : public true_type {};
template <>
struct _is_integral<unsigned long> : public true_type {};
template <>
struct _is_integral<long long> : public true_type {};
template <>
struct _is_integral<unsigned long long> : public true_type {};

template <typename T>
struct is_integral : public _is_integral<typename remove_cv<T>::type> {};

template <typename T, typename U>
struct is_same : public false_type {};

template <typename T>
struct is_same<T, T> : public true_type {};

template <typename>
struct void_t {
	typedef void type;
};

} /* namespace ft finished */
#endif // typename traits finished. 