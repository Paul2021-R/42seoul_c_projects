/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:36 by haryu             #+#    #+#             */
/*   Updated: 2022/12/21 16:15:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "algorithm.hpp"
#include "iterator.hpp"

#define FT_NOEXCEPT throw()

namespace ft {

/**
 * @brief RAII 구현을 위한 벡터의 기반 클래스
 * 
 * @tparam _T : Vector 의 type
 * @tparam _Allocator : 할당 공간
 */
template <typename _T, typename _Allocator = std::allocator<_T>()>
struct __vector_base {
public:
typedef _Allocator allocator_type;

protected:
typedef _T value_type;
typedef typename allocator_type::reference reference;
typedef typename allocator_type::const_reference const_reference;
typedef typename allocator_type::size_type size_type;
typedef typename allocator_type::difference_type difference_type;
typedef typename allocator_type::pointer pointer;
typedef typename allocator_type::const_pointer const_pointer;

/**
 * @brief vector start point
 * 
 */
pointer __begin_;
/**
 * @brief vector end point
 * 
 */
pointer __end_;
/**
 * @brief capacity of vector
 * 
 */
pointer __end_cap_;
/**
 * @brief storage
 * 
 */
allocator_type __a_;

__vector_base() FT_NOEXCEPT;
__vector_base(const allocator_type& a) FT_NOEXCEPT;
__vector_base(size_type n);
__vector_base(size_type n, const allocator_type & alloc);
~__vector_base() FT_NOEXCEPT {
	if(__begin_)
		__a_.deallocate(__begin_, __capacity());
}

size_type __capacity() const FT_NOEXCEPT {
	return static_cast<size_type>(this->__end_cap_ - this->__begin_);
}

size_type __check_length(size_type __n) {
	if (__n > this->__a_.max_size())
		__throw_length_error("size is too big");
	return __n;
}

void __destruct_storage() FT_NOEXCEPT;

pointer __construct_storage(size_type __n) {
	return __n == 0 ? pointer() : __a_.allocate(__n);
};

void __copy_data(__vector_base const & _other) FT_NOEXCEPT;
void __copy_data(pointer const & __new_begin_, pointer const & __new_end_, pointer const & __new_end_cap_) FT_NOEXCEPT;

void __swap_data(__vector_base & _otehr) FT_NOEXCEPT;

void __throw_length_error(const char * msg) const {
	throw std::length_error(msg);
}
void __throw_out_of_range(const char * msg) const {
	throw std::out_of_range(msg);
}

private:
/**
 * @brief Construct a new vector base object, 복사 생성자 구현 안함.
 * 
 * @param other 
 */
__vector_base(const __vector_base& other) { (void)other; }
/**
 * @brief copy assignment operator, 복사 할당 연산자 구현 안함. 
 * 
 * @param other 
 * @return __vector_base& 
 */
__vector_base & operator=(const __vector_base& other) { (void)other; }
};

template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base() FT_NOEXCEPT :
	__begin_(NULL),
	__end_(NULL),
	__end_cap_(NULL),
	__a_(std::allocator<_T>()) {}

template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base(const allocator_type & a) FT_NOEXCEPT :
	__begin_(NULL),
	__end_(NULL),
	__end_cap_(NULL),
	__a_(a) {}

template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base(size_type __n) : __a_(std::allocator<_T>()) {
	__begin_ = __construct_storage(__n);
	__end_ = __begin_;
	__end_cap_ = __begin_ + __n; 
}

template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base(size_type __n, const allocator_type & a) : __a_(a) {
	__begin_ = __construct_storage(__n);
	__end_ = __begin_;
	__end_cap_ = __begin_ + __n; 
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__copy_data(__vector_base const & _other) FT_NOEXCEPT {
	__begin_ = _other.__begin_;
	__end_ = _other.__end_;
	__end_cap_ = _other.__end_cap_;
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__copy_data(pointer const & __new_begin_, pointer const & __new_end_, pointer const & __new_end_cap_) FT_NOEXCEPT {
	__begin_ = __new_begin_; 
	__end_ = __new_end_;
	__end_cap_ = __new_end_cap_;
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__swap_data(__vector_base& _other) FT_NOEXCEPT {
	pointer __temp_begin_(__begin_);
	pointer __temp_end_(__end_);
	pointer __temp_end_cap_(__end_cap_);
	allocator_type __temp_a_(__a_);
	this->__copy_data(_other);
	this->__a_ = _other.__a_;
	_other.__copy_data(__temp_begin_, __temp_end_, __temp_end_cap_);
	_other.__a_ = __temp_a_;
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__destruct_storage() FT_NOEXCEPT {
	__a_.deallocate(__begin_, __capacity());
	__end_ = __begin_ = __end_cap_ = NULL;
}

/**
 * @brief vector 를 위한 반복자 구현
 * 
 * @tparam _Iter 
 */
template <typename _Iter>
class __vector_iterator {
public:
	typedef _Iter iterator_type;
	typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
	typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
	typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
	typedef typename ft::iterator_traits<iterator_type>::reference reference;

private:
iterator_type __it;

public:
__vector_iterator() FT_NOEXCEPT {}

template <typename _U> 
__vector_iterator(const __vector_iterator<_U>& __u, typename enable_if<__is_random_access_iterator<_U>::value>::type* = 0) FT_NOEXCEPT : __it(__u.base()) {}

__vector_iterator(iterator_type __x) FT_NOEXCEPT: __it(__x) {}
const iterator_type & base() const { return __it; }

/* 연산자  */
reference operator*() const FT_NOEXCEPT { return *__it; }
pointer operator->() const FT_NOEXCEPT { return __it; }
__vector_iterator& operator++() FT_NOEXCEPT {
	++__it;
	return *this;
}
__vector_iterator operator++(int) FT_NOEXCEPT {
	__vector_iterator __temp(*this);
	++(*this);
	return __temp;
}
__vector_iterator& operator--() FT_NOEXCEPT {
	--__it;
	return *this;
}
__vector_iterator operator--(int) FT_NOEXCEPT {
	__vector_iterator __temp(*this);
	--(*this);
	return __temp;
}
__vector_iterator& operator+=(difference_type __n) {
	__it += __n;
	return *this;
}
__vector_iterator operator+(difference_type __n) const {
	__vector_iterator __w(*this);
	__w += __n;
	return __w;
}
__vector_iterator& operator-=(difference_type __n) {
	__it -= __n;
	return *this;
}
__vector_iterator operator-(difference_type __n) const {
	__vector_iterator __w(*this);
	__w -= __n;
	return __w;
}
reference operator[](difference_type __n) { return __it[__n]; }
};

template <typename _Iter1, typename _Iter2>
bool operator==(const __vector_iterator<_Iter1>& __lhs, const __vector_iterator<_Iter2>& __rhs) {
	return __lhs.base() == __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator!=(const __vector_iterator<_Iter1>& __lhs, const __vector_iterator<_Iter2>& __rhs) {
	return __lhs.base() != __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator<(const __vector_iterator<_Iter1>& __lhs, const __vector_iterator<_Iter2>& __rhs) {
	return __lhs.base() < __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator>(const __vector_iterator<_Iter1>& __lhs, const __vector_iterator<_Iter2>& __rhs) {
	return __lhs.base() > __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator>=(const __vector_iterator<_Iter1>& __lhs, const __vector_iterator<_Iter2>& __rhs) {
	return __lhs.base() >= __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator<=(const __vector_iterator<_Iter1>& __lhs, const __vector_iterator<_Iter2>& __rhs) {
	return __lhs.base() <= __rhs.base();
}

template <typename _Iter1, typename _Iter2>
typename __vector_iterator<_Iter1>::difference_type operator-(
const __vector_iterator<_Iter1>& __lhs, const __vector_iterator<_Iter2>& __rhs){
	return __lhs.base() - __rhs.base();
}

template <typename _Iter>
__vector_iterator<_Iter> operator+(typename __vector_iterator<_Iter>::difference_type __n, const __vector_iterator<_Iter>& __it) {
	return __vector_iterator<_Iter>(__it.base() + __n);
}
// iterator implementation finshed.
/**
 * @brief 구현한 벡터 클래스
 * 
 * @tparam _T 각 요소들의 타입
 * @tparam _Allocator 벡터의 할당자
 */
template <typename _T, typename _Allocator = std::allocator<_T> >
class vector : private __vector_base<_T, _Allocator> {
private:
typedef __vector_base<_T, _Allocator> __base;

public:
typedef _T value_type;
typedef _Allocator allocator_type;
typedef typename __base::reference reference;
typedef typename __base::const_reference const_reference;
typedef typename __base::size_type size_type;
typedef typename __base::difference_type difference_type;
typedef typename __base::pointer pointer;
typedef typename __base::const_pointer const_pointer;

typedef __vector_iterator<pointer> iterator;
typedef __vector_iterator<const_pointer> const_iterator;
typedef ft::reverse_iterator<iterator> reverse_iterator;
typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

/* constructor */
explicit vector(const allocator_type & Alloc = allocator_type());
explicit vector(size_type n);
explicit vector(size_type n, const value_type& val);
vector(size_type n, const value_type & val, const allocator_type& Alloc);
template <typename _InputIterator>
vector(_InputIterator first, typename enable_if<__is_input_iterator<_InputIterator>::value && !__is_forward_iterator<_InputIterator>::value, _InputIterator>::type last, const allocator_type & Alloc = allocator_type());

/**
 * @brief Construct a new vector object, Iterator 활용 구간, 오버로드 정상작동 여부 확인 필요.
 * 
 * @tparam _ForwardIterator 
 * @param first 
 * @param last 
 * @param Alloc 
 */
template <typename _ForwardIterator>
vector(_ForwardIterator first, typename enable_if<__is_forward_iterator<_ForwardIterator>::value, _ForwardIterator>::type last, const allocator_type& Alloc = allocator_type());
vector(const vector<_T, _Allocator>& other);

// 할당 연산자
vector& operator=(const vector& rhs);

// 반복자 메소드
iterator begin() FT_NOEXCEPT { return this->__begin_; }
const_iterator begin() const { return this->__begin_; }
iterator end() FT_NOEXCEPT { return this->__end_; }
const_iterator end() const { return this->__end_; }

// reverse 반복자 메소드 
reverse_iterator rbegin() { return reverse_iterator(end()); }
const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
reverse_iterator rend() { return reverse_iterator(begin()); }
const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

// capacity 관련 함수들 
size_type size() const { return ft::distance(this->__begin_, this->__end_); }
size_type max_size() const { 
	return std::min(
		static_cast<size_type>(std::numeric_limits<difference_type>::max()), this->__a_.max_size()
	);
}
void resize(size_type n, value_type val = value_type());
size_type capacity() const { return this->__capacity(); }
bool empty() const { return this->__begin_ == this ->__end_; }
void reserve(size_type n);

// element access 
reference operator[](size_type n) { return reference(*(this->__begin_ + n)); }
const_reference operator[](size_type n) const {
	return const_referecnce(*(this->__begin_ + n));
}
reference at(size_type n) {
	if (n > this->size())
		this->__throw_out_of_range("vector: out of range");
	return *(this->__begin_ + n);
}
const_reference at(size_type n) const {
	if (n > this->size())
		this->__throw_out_of_range("vector: out of range");
	return *(this->__begin_ + n);
}
reference front() { return *this->__begin_; }
const_reference front() const { return *this->__begin_; }
reference back() { return *(this->__end_ - 1); } // 1개 빼야 하는 이유는?
const_reference back() const { return *(this->__end_ - 1); } // 1개 빼야 하는 이유는?

// modifiers 
template <typename _InputIterator>
void assign(_InputIterator first, typename enable_if<__is_input_iterator<_InputIterator>::value && !__is_forward_iterator<_InputIterator>::value, _InputIterator>::type last);
template <typename _ForwardIterator>
void assign(_ForwardIterator first, typename enable_if<__is_forward_iterator<_ForwardIterator>::value, _ForwardIterator>::type last);
void assign(size_type n, const value_type& val);
void push_back(const value_type & val);
void pop_back() FT_NOEXCEPT;
iterator insert(iterator position, const value_type& val);
void insert(iterator position, size_type n, const value_type& val);
template <typename _InputIterator>
void insert (iterator position, _InputIterator first, typename enable_if<__is_input_iterator<_InputIterator>::value && !__is_forward_iterator<_InputIterator>::value, _InputIterator>::type last);
template <typename _ForwardIterator>
void insert(iterator position, _ForwardIterator first, typename enable_if<__is_forward_iterator<_ForwardIterator>::value, _ForwardIterator>::type last);
iterator erase(iterator position);
iterator erase(iterator first, iterator last);
void swap(vector & x) { this->__swap_data(x); }
void clear() FT_NOEXCEPT {
	if (this->__begin_)
		__destroy_from_end(this->__begin_);
}

// Allocator 할당기 
allocator_type get_allogator() const FT_NOEXCEPT { return this->__a_; }

~vector() FT_NOEXCEPT {
	if (this->__begin_) {
		clear();
		this->__destruct_storage();
	}
}

private:
void __reconstruct_push_back(const value_type & val);
void __reallocate(size_type __n);
void __destroy_from_end(pointer __new_end);
};

// 생성자 함수 정리 
template <typename _T, typename _Allocator>
vector<_T, _Allocator>::vector(const allocator_type& Alloc) : __vector_base<_T, _Allocator>(size_type(), Alloc) {}

template <typename _T, typename _Allocator>
vector<_T, _Allocator>::vector(size_type n) : __vector_base<_T, _Allocator>(n, allocator_type()) {
	std::uninitialized_fill(this->__begin_, this->__begin_ + n, value_type());
	this->__end_ += n;
}

template <typename _T, typename _Allocator>
vector<_T, _Allocator>::vector(size_type n, const value_type& val) : __vector_base<_T, _Allocator>(n, allocator_type()) {
	std::uninitialized_fill(this->__begin_, this->__begin_ + n, val);
	this->__end_ += n;
}

template <typename _T, typename _Allocator>
vector<_T, _Allocator>::vector(size_type n, const value_type& val, const allocator_type& Alloc) : __vector_base<_T, _Allocator>(n, Alloc) {
	std::uninitialized_fill(this->__begin_, this->__begin_ + n, val);
	this->__end_ += n;
}

template <typename _T, typename _Allocator>
template <typename _InputIterator>
vector<_T, _Allocator>::vector(_InputIterator first, typename enable_if<__is_input_iterator<_InputIterator>::value && !__is_forward_iterator<_InputIterator>::value, _InputIterator>::type last, const allocator_type& Alloc) : __vector_base<_T, _Allocator>(size_type(), Alloc){
	for(; first != last; ++first)
		push_back(*first);
}

template <typename _T, typename _Allocator>
template <typename _ForwardIterator>
vector<_T, _Allocator>::vector(_ForwardIterator first, typename enable_if<__is_forward_iterator<_ForwardIterator>::value, _ForwardIterator>::type last, const allocator_type& Alloc) : __vector_base<_T, _Allocator>(static_cast<size_type>(ft::distance(first, last)), Alloc) {
	this->__end_ = std::uninitialized_copy(first, last, this->__begin_);
}

template<typename _T, typename _Allocator>
vector<_T, _Allocator>::vector(const vector<_T, _Allocator>& other) : __vector_base<_T, _Allocator>(other.capacity()) {
	clear();
	this->__end_ = std::uninitialized_copy(other.__begin_, other.__end_, this->__begin_);
}

template <typename _T, typename _Allocator>
vector<_T, _Allocator>& vector<_T, _Allocator>::operator=(const vector<_T, _Allocator>& other) {
	if (this != &other) {
		if (this->__a_ != other.__a_) {
			clear();
			this->__a_.deallocate(this->__begin_, capacity());
			this->__begin_ = this->__end_ = this->__end_cap_ = NULL;
			this->__a_ = other.__a_;
		}
		assign(other.__begin_, other.__end_);
	}
	return *this;
}

/* private 멤버 함수들 */
template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::__reconstruct_push_back(const value_type& val) {
	size_type __cap = this->__capacity();
	size_type __max_size = this->max_size();
	size_type __new_size = __cap > (__max_size >> 1) ? __max_size : __cap << 1;

	if (__new_size == 0)
		__new_size = 1;
	reserve(__new_size);
	this->__a_.construct(this->__end_, val);
	++this->__end_;
}

template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::__reallocate(size_type __n) {
	vector<_T, _Allocator> temp(__n);
	std::uninitialized_copy(this->__begin_, this->__end_, temp.__begin_);
	temp.__end_ = temp.__begin_ + size();
	this->__swap_data(temp); 
}

template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::__destroy_from_end(pointer __new_end) {
	pointer __be_end = this->__end_;
	while (__new_end != __be_end) {
		--__be_end;
		this->__a_.destroy(__be_end);
	}
	this->__end_ = __new_end;
}

// public 멤버 메소드 
// capacity 
template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::reserve(size_type n) {
	size_type __new_size = this->__check_length(n);
	if (__new_size > capacity()) {
		__reallocate(__new_size);
	}
}

template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::resize(size_type n, value_type val) {
	size_type __prev_size = size();
	if (n < __prev_size) {
		__destroy_from_end(this->__begin_ + n);
		return;
	}
	else if (n > capacity()){
		__reallocate(n);
	}
	insert(end(), n - __prev_size, val);
}

//modifiers 메소드

template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::assign(size_type n, const value_type& val) {
	if (n < this->capacity()) {
		this->clear();
		std::uninitialized_fill(this->__begin_, this->__begin_ + n, val);
		this->__end_ += n;
		return ;
	}
	vector<_T, _Allocator> temp(n, val);
	this->__swap_data(temp);
}

template <typename _T, typename _Allocator>
template <typename _InputIterator>
void vector<_T, _Allocator>::assign(_InputIterator first, typename enable_if<__is_input_iterator<_InputIterator>::value && !__is_forward_iterator<_InputIterator>::value, _InputIterator>::type last) {
	this->clear();
	for (; first != last; ++first) {
		push_back(*first);
	}
}

template <typename _T, typename _Allocator>
template <typename _ForwardIterator>
void vector<_T, _Allocator>::assign(_ForwardIterator first, typename enable_if<__is_forward_iterator<_ForwardIterator>::value, _ForwardIterator>::type last) {
	size_type __new_n = ft::distance(first, last);
	if (__new_n < this->capacity()) {
		this->clear();
		this->__end_ = std::uninitialized_copy(first, last, this->__begin_);
		return ;
	}
	vector<_T, _Allocator> temp(first, last);
	this->__swap_data(temp);
}

template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::push_back(const value_type& val) {
	if (this->__end_ != this->__end_cap_) {
		this->__a_.construct(this->__end_++, val);
		return ;
	}
	this->__reconstruct_push_back(val);
}

template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::pop_back() FT_NOEXCEPT {
	if (!(this->empty()))
		this->__destroy_from_end(this->__end_ - 1);
}

template <typename _T, typename _Allocator>
typename vector<_T, _Allocator>::iterator vector<_T, _Allocator>::insert(iterator position, const value_type& val) {
	difference_type __diff = position - begin();
	if (this->__end_ == this->__end_cap_)
		this->reserve(size_type(this->capacity() + 1));
	
	pointer __p = this->__begin_ + __diff;
	pointer __old_end = this->__end_;
	while(__old_end != __p) {
		--__old_end;
		this->__a_.construct(__old_end + 1, *(__old_end));
		this->__a_.destroy(__old_end);
	}
	this->__a_.construct(__p, val);
	++this->__end_;
	return iterator(this->__begin_ + __diff);
}

template <typename _T, typename _Allocator>
void vector<_T, _Allocator>::insert(iterator position, size_type n, const value_type & val) {
	difference_type __diff = position - this->begin();
	if (this->size() + n > this->capacity())
		this->reserve(this->size() + n);
	
	pointer __p = this->__begin_ + __diff;
	pointer __old_end = this->__end_;

	while (__old_end != __p) {
		--__old_end;
		this->__a_.construct(__old_end + n, *(__old_end));
		this->__a_.destroy(__old_end);
	}
	std::uninitialized_fill(__p, __p + n, val);
	this->__end_ += n;
}

template <typename _T, typename _Allocator>
template <typename _InputIterator>
void vector<_T, _Allocator>::insert(iterator position, _InputIterator first, typename enable_if<__is_input_iterator<_InputIterator>::value && !__is_forward_iterator<_InputIterator>::value, _InputIterator>::type last) {
	difference_type __diff = position - this->begin();
	pointer __p = this->__begin_ + __diff;
	pointer __old_end = this->__end_;

	for (int i = 0; first != last; ++first, ++i) {
		this->insert(position + i, *first);
	}

}

template <typename _T, typename _Allocator>
template <typename _ForwardIterator>
void vector<_T, _Allocator>::insert(iterator position, _ForwardIterator first, typename enable_if<__is_forward_iterator<_ForwardIterator>::value, _ForwardIterator>::type last) {
	difference_type __in_size = ft::distance(first, last);
	difference_type __diff = position - this->begin();
	if (__in_size <= 0)
		return ;
	if (__in_size + this->size() > this->capacity())
		reserve(__in_size + this->size());

	pointer __p = this->__begin_ + __diff;
	pointer __old_end = this->__end_;
	
	while (__old_end != __p) {
		--__old_end;
		this->__a_.construct(__old_end + __in_size, *(__old_end));
		this->__a_.destroy(__old_end);
	}
	std::uninitialized_copy(first, last, __p);
	this->__end_ += __in_size;
}

template <typename _T, typename _Allocator>
typename vector<_T, _Allocator>::iterator vector<_T, _Allocator>::erase(iterator position) {
	difference_type __diff = position - this->begin();
	pointer __p = this->__begin_ + __diff;

	this->__a_.destroy(__p);
	this->__a_.destroy(std::uninitialized_copy(__p + 1, this->__end_--, __p));
	return (iterator(this->__begin_ + __diff));
}

template <typename _T, typename _Allocator>
typename vector<_T, _Allocator>::iterator vector<_T, _Allocator>::erase(iterator first, iterator last) {
	difference_type __diff = first - this->begin();
	pointer __p = this->__begin_ + __diff;

	if (last == this->end()) {
		__destroy_from_end(__p);
		return iterator(this->__begin_ + __diff);
	}

	difference_type __range = last - first;
	pointer __p_last = __p + __range;
	pointer __new_end = this->__end_ - __range;

	for (difference_type i = 0; i <= __range; ++i) {
		this->__a_.destroy(__p + i);
		if (i <= this->__end_ - __p_last)
			this->__a_.construct(__p + i, *(__p_last + i));
	}
	__destroy_from_end(__new_end);
	return (iterator(this->__begin_ + __diff));
}

// 멤버가 아닌 함수 오버로드 
// 비교 연산자
template <typename _T, typename _Allocator>
inline bool operator==(const vector<_T, _Allocator>& lhs, const vector<_T, _Allocator>& rhs) {
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename _T, typename _Allocator>
inline bool operator!=(const vector<_T, _Allocator>& lhs, const vector<_T, _Allocator>& rhs) {
	return !(lhs == rhs);
}

template <typename _T, typename _Allocator>
inline bool operator<(const vector<_T, _Allocator>& lhs, const vector<_T, _Allocator>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename _T, typename _Allocator>
inline bool operator<=(const vector<_T, _Allocator>& lhs, const vector<_T, _Allocator>& rhs) { return !(lhs > rhs); }

template <typename _T, typename _Allocator>
inline bool operator>(const vector<_T, _Allocator>& lhs, const vector<_T, _Allocator>& rhs) { return rhs < lhs; }

template <typename _T, typename _Allocator>
inline bool operator>=(const vector<_T, _Allocator>& lhs, const vector<_T, _Allocator>& rhs) { return !(rhs > lhs); }

//swap 메소드
template <typename _T, typename _Allocator>
inline void swap(ft::vector<_T, _Allocator>& x, ft::vector<_T, _Allocator>& y) {
	x.swap(y);
}

} // namespace vector 

#endif