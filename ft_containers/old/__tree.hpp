/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:12:35 by haryu             #+#    #+#             */
/*   Updated: 2022/12/22 00:30:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TREE_HPP
#define __TREE_HPP

#include <memory>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "utility.hpp"

#define FT_NOEXCEPT throw()

namespace ft {

enum __tree_node_color { RED = false, BLACK = true };

struct __tree_node_base;

__tree_node_base * __tree_increment(__tree_node_base * __x) FT_NOEXCEPT;
const __tree_node_base * __tree_increment(const __tree_node_base * __x) FT_NOEXCEPT;

__tree_node_base * __tree_decrement(__tree_node_base *__x) FT_NOEXCEPT;
const __tree_node_base * __tree_decrement(const __tree_node_base *__x) FT_NOEXCEPT;

void __tree_rotate_left(const __tree_node_base * __x, const __tree_node_base *&__root);
void __tree_rotate_right(const __tree_node_base * __x, const __tree_node_base *&__root);

void __tree_insert_and_fixup(const bool __insert_left, __tree_node_base * __x, __tree_node_base * __p, __tree_node_base & __header) FT_NOEXCEPT;

__tree_node_base * __tree_erase_and_fixup(const __tree_node_base * __z, __tree_node_base & __header) FT_NOEXCEPT;

__tree_node_base * __minimum(__tree_node_base * __x) FT_NOEXCEPT;
const __tree_node_base * __minimum(const __tree_node_base * __x) FT_NOEXCEPT;
__tree_node_base * __maximum(__tree_node_base * __x) FT_NOEXCEPT;
const __tree_node_base * __maximum(const __tree_node_base * __x) FT_NOEXCEPT;

/**
 * @brief tree 노드들 
 * 
 */
// RB 트리 구현을 위한 노드 구조체의 기반 
struct __tree_node_base {
	typedef __tree_node_base *_Base_ptr;
	typedef const __tree_node_base *_Const_base_ptr;

	__tree_node_color __color_;
	_Base_ptr __parent_;
	_Base_ptr __left_;
	_Base_ptr __right_;
};

// 트리 헤더 
struct __tree_header {
	__tree_node_base __header_;
	size_t __node_count_;

	__tree_header() {
		__header_.__color_ = RED;
		__tree_reset();
	}

	void __tree_reset();
	void __tree_move_data(__tree_header & other);
};

template <typename _Key_compare>
struct __tree_key_compare {
	_Key_compare __key_comp;
	
	__tree_key_compare() : __key_comp() {}
	__tree_key_compare(const _Key_compare & other) : __key_comp(other) {}
};

// RB 트리 실제 노드
template <typename _Val>
struct __tree_node : public __tree_node_base {
	typedef __tree_node<_Val> * _Link_type;

	_Val __value_field;
	_Val * __valptr() { return & __value_field; }
	const _Val * __valptr() const { return & __value_field; }
};

/**
 * @brief Tree 노드 반복자
 * 
 */

template <typename _T>
struct __tree_iterator : public iterator<bidirectional_iterator_tag, _T> {
	typedef _T value_type;
	typedef _T &reference;
	typedef _T *pointer;
	typedef bidirectional_iterator_tag iterator_category;
	typedef ptrdiff_t differnece_type;

	typedef __tree_iterator<_T> iterator_type;
	typedef __tree_node_base::_Base_ptr _Base_ptr;
	typedef __tree_node<_T> * _Link_type;

	_Base_ptr __node_;

	__tree_iterator() : __node_() {}
	__tree_iterator(const __tree_iterator & other) : __node_(other.__node_) {}
	explicit __tree_iterator(_Base_ptr __x): __node_(__x) {}

	reference operator*() const FT_NOEXCEPT {
		return *static_cast<_Link_type>(__node_)->__valptr();
	}

	pointer operator->() const FT_NOEXCEPT {
		return static_cast<_Link_type>(__node_)->__valptr();
	}

	iterator_type & operator++() FT_NOEXCEPT {
		__node_ = __tree_increment(__node_);
		return *this;
	}

	iterator_type operator++(int) FT_NOEXCEPT {
		iterator_type __temp(*this);
		++(*this);
		return __temp;
	}

	iterator_type & operator--() FT_NOEXCEPT {
		__node_ = __tree_decrement(__node_);
		return *this;
	}

	iterator_type operator--(int) FT_NOEXCEPT {
		iterator_type __temp(*this);
		--(*this);
		return __temp;
	}

	friend bool operator==(const iterator_type &lhs, const iterator_type &rhs) FT_NOEXCEPT {
		return lhs.__node_ == rhs.__node_;
	}

	friend bool operator!=(const iterator_type &lhs, const iterator_type &rhs) FT_NOEXCEPT {
		return lhs.__node_ != rhs.__node_;
	}

};

template <typename _T>
struct __tree_const_iterator : public iterator<bidirectional_iterator_tag, _T> {
	typedef _T value_type;
	typedef const _T& reference;
	typedef const _T* pointer;
	typedef bidirectional_iterator_tag iterator_category;
	typedef ptrdiff_t differnece_type;

	typedef __tree_iterator<_T> iterator;
	typedef __tree_iterator<_T> iterator_type;
	typedef __tree_const_iterator<_T> const_iterator_type;
	typedef __tree_node_base::_Const_base_ptr _Base_ptr;
	typedef __tree_node<_T> *_Link_type;
	typedef const __tree_node<_T> * _Const_link_type;

	_Base_ptr __node_;

	__tree_const_iterator() FT_NOEXCEPT : __node_() {}

	explicit __tree_const_iterator(_Base_ptr __x) FT_NOEXCEPT : __node_(__x) {}
	__tree_const_iterator(const __tree_const_iterator & other) : __node_(other.__node_) {}
	__tree_const_iterator(iterator __itr) :__node_(__itr.__node_) {}

	iterator __remove_const() const FT_NOEXCEPT {
		return iterator(const_cast<typename iterator::_Base_ptr>(__node_));
	}

	reference operator*() const FT_NOEXCEPT {
		return *static_cast<_Link_type>(__node_)->__valptr();
	}

	pointer operator->() const FT_NOEXCEPT {
		return static_cast<_Const_link_type>(__node_)->__valptr();
	}

	const_iterator_type & operator++() FT_NOEXCEPT {
		__node_ = __tree_increment(__node_);
		return *this;
	}

	const_iterator_type operator++(int) FT_NOEXCEPT {
		const_iterator_type __temp(*this);
		++(*this);
		return __temp;
	}

	const_iterator_type & operator--() FT_NOEXCEPT {
		__node_ = __tree_decrement(__node_);
		return *this;
	}

	const_iterator_type operator--(int) FT_NOEXCEPT {
		const_iterator_type __temp(*this);
		--(*this);
		return __temp;
	}

	friend bool operator==(const const_iterator_type &lhs, const const_iterator_type &rhs) FT_NOEXCEPT {
		return lhs.__node_ == rhs.__node_;
	}

	friend bool operator!=(const const_iterator_type &lhs, const const_iterator_type &rhs) FT_NOEXCEPT {
		return lhs.__node_ != rhs.__node_;
	}

};

/**
 * @brief RB 트리 클래스 구현
 * 
 * @tparam _Key : 각 노드들의 키값
 * @tparam _Val : 각 노드들의 실제 값
 * @tparam _KeyofValue : 값 functor 의 키를 받아오기 
 * @tparam _Compare : functor 비교용 
 * @tparam _Alloc : 할당자(기본값은 std::allocator<_Val>)
 */
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<_Val> >
class __tree {
private:
	typedef __tree_node_base * _Base_ptr;
	typedef const __tree_node_base * _Const_base_ptr;
	typedef __tree_node<_Val> * _Link_type;
	typedef const __tree_node<_Val> * _Const_link_type;

public:
	typedef _Key key_type;
	typedef _Val value_type;
	typedef value_type * pointer;
	typedef const value_type * const_pointer;
	typedef value_type & reference;
	typedef const value_type & const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef _Alloc allocator_type;

	typedef typename _Alloc::template rebind<__tree_node<_Val> >::other _Node_allocator;

	typedef __tree_iterator<value_type> iterator;
	typedef __tree_const_iterator<value_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
	/**
	 * @brief 트리의 데이터 구현
	 * 
	 * @class _Node_allocator : rebind of allocator
	 * @class __tree_key_compare : key compare 함수 객체 
	 * @class  __tree_header : 트리의 헤드
	 */
	template <typename _Key_compare>
	struct __tree_impl : public _Node_allocator, public __tree_key_compare<_Key_compare>, public __tree_header {
		typedef __tree_key_compare<_Key_compare> _Base_key_compare;

		__tree_impl() : _Node_allocator()  {}
		__tree_impl(const __tree_impl & other) :
			_Node_allocator(other),
			_Base_key_compare(other.__key_comp),
			__tree_header() {}
		__tree_impl(const _Key_compare & __comp, const _Node_allocator & __a) :
			_Node_allocator(__a), 
			_Base_key_compare(__comp) {}
	};

	__tree_impl<_Compare> __impl_;

	_Node_allocator & __get_Node_allocator() { return this->__impl_; }
	const _Node_allocator & __get_Node_allocator() const { return this->__impl_; }

	_Link_type __allocate_node() { return __get_Node_allocator().allocate(1); }

	void __deallocate_node(_Link_type __p) { __get_Node_allocator().deallocate(__p, 1); }

	void __construct_node(_Link_type __node, const value_type& __x) {
		get_allocator().construct(__node->__valptr(), __x);
	}

	_Link_type __create_node(const value_type & __x) {
		_Link_type __temp = __allocate_node();
		__construct_node(__temp, __x);
		return __temp;
	}

	void __destroy_node(_Link_type __p) {
		get_allocator().destroy(__p->__valptr());
	}

	// Return : __x의 값과 컬러의 복사본을 새로운 노드에게 반환한다. 
	_Link_type __clone_node(_Link_type __x) {
		_Link_type __temp = this->__create_node(*__x->__valptr());
		__temp->__color_ = __x->__color_;
		__temp->__left_  = NULL;
		__temp->__right_ = NULL;
		return __temp;
	}

	// section : 특정 노드 찾기 

	// section : base-node 타입을 반환한다. 
	_Base_ptr & __root() { return this->__impl_.__header_.__parent_; }
	_Const_base_ptr __root() const { return this->__impl_.__header_.__left_; }

	_Base_ptr & __leftmost() { return this->__impl_.__header_.__left_; }
	_Const_base_ptr __leftmost() const { return this->__impl_.__header_.__left_; }

	_Base_ptr & __rightmost() { return this->__impl_.__header_.__right_; }
	_Const_base_ptr __rightmost() const { return this->__impl_.__header_.__right_; }

	_Base_ptr __end() { return &this->__impl_.__header_; }
	_Const_base_ptr __end() const { return &this->__impl_.__header_; }

	static _Base_ptr __S_minimum(_Base_ptr __x) { return __minimum(__x); }
	static _Const_base_ptr __S_minimum(_Const_base_ptr __x) { return __minimum(__x); }

	static _Base_ptr __S_maximum(_Base_ptr __x) {return __maximum(__x); }
	static _Const_base_ptr __S_maximum(_Const_base_ptr __x) {return __maximum(__x); }

	// section : 키값의 타입을 반환하눈 함수
	static const _Key & __S_key(_Const_link_type __x) { return _KeyofValue()(*__x->__valptr()); }
	static const _Key & __S_key(_Const_base_ptr __x) { return __S_key(static_cast<_Const_link_type>(__x)); }

	// section : node 값의 타입을 반환하눈 함수
	_Link_type __begin() {
		return static_cast<_Link_type>(this->__impl_.__header_.__parent_);
	}

	_Const_link_type __begin() const {
		return static_cast<_Link_type>(this->__impl_.__header_.__parent_);
	}
	
	static _Link_type __S_left(_Base_ptr __x) {
		return static_cast<_Link_type>(__x->__left_);
	}
	static _Const_link_type __S_left(_Const_base_ptr __x) {
		return static_cast<_Link_type>(__x->__left_);
	}

	static _Link_type __S_right(_Base_ptr __x) {
		return static_cast<_Link_type>(__x->__right_);
	}
	static _Const_link_type __S_right(_Const_base_ptr __x) {
		return static_cast<_Link_type>(__x->__right_);
	}

	// section: public 멤버 함수를 위한 도구들 

	// 삽입할 위치 파악 하기 
	ft::pair<_Base_ptr, _Base_ptr> __get_insert_unique_pos(const key_type & __k);
	// 힌트 그리고 위치 정보 얻기 
	ft::pair<_Base_ptr, _Base_ptr> __get_insert_hint_unique_pos(const_iterator __pos, const key_type & __k);

	_Link_type __copy_tree(_Link_type __x, _Base_ptr __p);
	_Link_type __copy_tree(const __tree & __t) {
		// copy whole tree
		_Link_type __root = __copy_tree(const_cast<_Link_type>(__t.__begin()), __end());
		// update header
		__leftmost() = __S_minimum(__root);
		__rightmost() = __S_maximum(__root);
		__impl_.__node_count_ = __t.__impl_.__node_count_;

		return __root;
	}

	void __delete_node(_Link_type __p) {
		__destroy_node(__p);
		__deallocate_node(__p);
	}

	void __erase_without_balance(_Link_type __x);
	void __erase_helper(const_iterator __position);
	void __erase_helper(const_iterator __first, const_iterator __last);

	iterator __lower_bound_helper(_Link_type __x, _Base_ptr __y, const key_type & __k);
	const_iterator __lower_bound_helper(_Const_link_type __x, _Const_base_ptr __y, const key_type & __k) const;

	iterator __upper_bound_helper(_Link_type __x, _Base_ptr __y, const key_type & __k);
	const_iterator __upper_bound_helper(_Const_link_type __x, _Const_base_ptr __y, const key_type & __k) const;

	iterator __insert_helper(_Base_ptr __x, _Base_ptr __p, const value_type & __v);

	// section : 생성자, 소멸자
public:
	__tree() {}
	__tree(const _Compare & _comp, const allocator_type & __a = allocator_type()) :
		__impl_(_comp, _Node_allocator(__a)) {}
	__tree(const __tree & other) :
		__impl_(other.__impl_) {
		if (other.__root() != NULL)
			__root() = __copy_tree(other);
	}
	~__tree() { __erase_without_balance(__begin()); }

	__tree& operator= (const __tree & other) {
		if (this != &other) {
			this->clear();
			__impl_.__key_comp = other.__impl_.__key_comp;
			if (other.__root() != NULL)
				__root() = __copy_tree(other);
		}
		return *this;
	}

	// section : public 멤버 함수 
	// 데이터 접근용 
	_Compare key_comp() const { return __impl_.__key_comp; }
	iterator begin() { return iterator(__impl_.__header_.__left_); }
	const_iterator begin() const { return const_iterator(__impl_.__header_.__left_); }

	iterator end() { return iterator(&__impl_.__header_); }
	const_iterator end() const { return const_iterator(&__impl_.__header_); }

	reverse_iterator rbegin() { return reverse_iterator(&__impl_.__header_); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(begin()); }

	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

	// 용량 확인
	bool empty() const { return __impl_.__node_count_ == 0; }
	size_type max_size() const { 
		return ft::min(__get_Node_allocator().max_size(), static_cast<size_type>(std::numeric_limits<difference_type>::max()));
	}
	size_type size() const { return __impl_.__node_count_; }

	// 수정자, modifiers
	void erase(iterator position) { __erase_helper(position); }
	void erase(const_iterator position) { __erase_helper(position); }
	size_type erase(const key_type & __v);
	void erase(iterator first, iterator last) { __erase_helper(first, last); }
	void erase(const_iterator first, const_iterator last) { __erase_helper(first, last); }
	
	void clear() {
		__erase_without_balance(__begin());
		__impl_.__tree_reset();	
	}

	void swap(__tree & __t);
	
	ft::pair<iterator, bool> insert_unique(const value_type & __v);

	iterator insert_unique_with_hint(const_iterator __position, const value_type & __v);

	template <typename _InputIterator>
	void insert_range(_InputIterator __first, _InputIterator __last) {
		for (; __first != __last; ++__first) {
			insert_unique_with_hint(end(), *__first);
		}
	}

	// 연산자들 
	/**
	 * @brief 제공되는 키값으로 노드를 찾고, 이를 반환한다. 없으면 반복자 끝end()를 반환한다. 
	 * 
	 * @param __k 
	 * @return iterator 
	 */
	iterator find(const key_type & __k) {
		iterator __found = __lower_bound_helper(__begin(), __end(), __k);
		if (__impl_.__key_comp(__k, __S_key(__found.__node_)) || __found == end())
			return end();
		return __found;
	}
	const_iterator find(const key_type & __k) const {
		const_iterator __found = __lower_bound_helper(__begin(), __end(), __k);
		if (__impl_.__key_comp(__k, __S_key(__found.__node_)) || __found == end())
			return end();
		return __found;
	}

	size_type count(const key_type & __k) const {
		const_iterator __found = find(__k);
		return __found == end() ? 0 : 1;
	}

	iterator lower_bound(const key_type & __k) {
		return __lower_bound_helper(__begin(), __end(), __k);
	}
	const_iterator lower_bound(const key_type & __k) const {
		return __lower_bound_helper(__begin(), __end(), __k);
	}

	iterator upper_bound(const key_type & __k) {
		return __upper_bound_helper(__begin(), __end(), __k);
	}
	const_iterator upper_bound(const key_type & __k) const { 
		return __upper_bound_helper(__begin(), __end(), __k);
	}

	pair<iterator, iterator> equal_range(const key_type & __k);
	pair<const_iterator, const_iterator> equal_range(const key_type & __k) const;

	allocator_type get_allocator() const { 
		return allocator_type(__get_Node_allocator());
	}

	// tree 출력 하기 
	void print_tree();
	static void print_tree(const std::string & prefix, _Link_type x, bool isLeft);
};

/**
 * @brief 삽입을 위한 특정 위치를 반환한다. 
 * @param __k 얻어야 할 위치
 * @return ft::pair<typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::_Base_ptr, typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::_Base_ptr> 
 * 			ret_pair.first : 만약 NULL 이 아니면, 왼쪽에 삽입, 그렇지 않으면 오른쪽에 삽입
 * 			ret_pair.second : 만약 NULL 이 아니면 삽입이 가능한 노드의 부모가 되며, 
 *								NULL이면 노드가 삽입하지 않는 flase 케이스로 구분한다. 
 */
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
ft::pair<typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::_Base_ptr, typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::_Base_ptr>
__tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__get_insert_unique_pos(const key_type & __k) {
	typedef ft::pair<_Base_ptr, _Base_ptr> ret_pair;

	_Link_type __x = __begin(); // __root
	_Base_ptr __y = __end(); // __header
	bool __comp = true;

	// 왼쪽 혹은 오른쪽이 잎을 만날 때까지 점검하기. __y는 잎(leaf)가 된다.
	while (__x != NULL) {
		__y = __x;
		__comp = __impl_.__key_comp(__k, __S_key(__x));
		__x = __comp ? __S_left(__x) : __S_right(__x);
	}

	iterator __j = iterator(__y);
	if (__comp) {
		if (__j == begin()) // leftmost
			return ret_pair(__x, __y); //(NULL, leaf)
		--__j; // decrement node
	}

	if(__impl_.__key_comp(__S_key(__j.__node_), __k)) // 잎(leaf) 과 __k값 비교하기
		return ret_pair(__x, __y); // (NULL, leaf) 이면 반환한다.
	return ret_pair(__j.__node_, NULL); // 1 줄인 leaf과 NULL(false) 반환
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
ft::pair<typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::_Base_ptr, typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::_Base_ptr>
__tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__get_insert_hint_unique_pos(const_iterator __pos, const key_type & __k) {
	iterator __copy_pos = __pos.__remove_const();
	typedef ft::pair<_Base_ptr, _Base_ptr> ret_pair;

	if (__pos.__node_ == __end()) {
		if (size() > 0 && __impl_.__key_comp(__S_key(__rightmost()), __k))
			return ret_pair(NULL, __rightmost());
		else
			return __get_insert_unique_pos(__k);
	}
	else if (__impl_.__key_comp(__k, __S_key(__copy_pos.__node_))) {
		// pos보다 적으면 
		iterator __before = __copy_pos;
		if (__copy_pos.__node_ == __leftmost()) {
			return ret_pair(__leftmost(), __leftmost());
		}
		else if (__impl_.__key_comp(__S_key(--__before.__node_), __k)) {
			if (__S_right(__before.__node_) == NULL)
				return ret_pair(NULL, __before.__node_);
			return ret_pair(__copy_pos.__node_, __copy_pos.__node_);
		}
		else { return __get_insert_unique_pos(__k); }
	}
	else if (__impl_.__key_comp(__S_key(__pos.__node_), __k)) {
		iterator __after = __copy_pos;

		if (__copy_pos.__node_ == __rightmost()) {
			return ret_pair(NULL, __rightmost());
		}
		else if (__impl_.__key_comp(__k, __S_key((++__after).__node_))) {
			if (__S_right(__copy_pos.__node_) == NULL)
				return ret_pair(NULL, __copy_pos.__node_);
			return ret_pair(__after.__node_, __after.__node_);
		}
		else { return __get_insert_unique_pos(__k); }
	}
	else { return ret_pair(__copy_pos.__node_, NULL); } // 위치가 같다. 키가 같을 순 없다. 
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__insert_helper(_Base_ptr __x, _Base_ptr __p, const value_type & __v) {
	bool __insert_left = (__x != 0 || __p == __end() || __impl_.__key_comp(_KeyofValue()(__v), __S_key(__p)));

	_Link_type __z = this->__create_node(__v);
	__tree_insert_and_fixup(__insert_left, __z, __p, this->__impl_.__header_);
	++__impl_.__node_count_;
	return iterator(__z);
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
ft::pair<typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator, bool>
__tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::insert_unique(const value_type & __v) {
	typedef ft::pair<iterator, bool> ret_pair;

	ft::pair<_Base_ptr, _Base_ptr> __ret = __get_insert_unique_pos(_KeyofValue()(__v)); // __v의 키값 기반으로 위치를 파악하기 용

	if (__ret.second) 
		return ret_pair(__insert_helper(__ret.first, __ret.second, __v), true);
	return ret_pair(iterator(__ret.first), false);
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator  __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::insert_unique_with_hint(const_iterator __position, const value_type & __v) {
	ft::pair<_Base_ptr, _Base_ptr> __ret = __get_insert_hint_unique_pos(__position, _KeyofValue()(__v));
	if (__ret.second) 
		return __insert_helper(__ret.first, __ret.second, __v);
	return iterator(__ret.first);
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::_Link_type __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__copy_tree(_Link_type __x, _Base_ptr __p) {
	_Link_type __top = __clone_node(__x); // 최근 노드의 값을 복사하기 
	__top->__parent_ = __p; // 부모랑 연결시키기 

	// 오른쪽 노드가 있다면 
	if (__x->__right_) {
		__top->__right_ = __copy_tree(__S_right(__x), __top); // 오른쪽 파트를 통으로 복사한다. 
	}
	__p = __top;
	__x = __S_left(__x);

	// 왼쪽 노드를 NULL 까지 복사하기 
	while (__x != NULL) {
		_Link_type __y = __clone_node(__x);
		__p->__left_ == __y;
		__y->__parent_ = __p;
		// 만약 left 노드가 우측이 있을 때, 다시 오른 쪽을 복사한다. 
		if (__x->__right_) { __y->__parent_ = __copy_tree(__S_right(__x), __y); }
		__p = __y;
		__x = __S_left(__x);
	}
	return __top;
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
void __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__erase_without_balance(_Link_type __x) {
	while (__x != NULL) {
		__erase_without_balance(__S_right(__x));
		_Link_type __y = __S_left(__x);
		__delete_node(__x);
		__x = __y;
	}
}

/**
 * @brief 특정 노드를 삭제하고, 벨런스 다시 맞추는 용
 * 
 * @param __position 
 */
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
void __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__erase_helper(const_iterator __position) {
	_Link_type __y = static_cast<_Link_type>(__tree_erase_and_fixup(const_cast<_Base_ptr>(__position.__node_), __impl_.__header_));
	__delete_node(__y);
	--__impl_.__node_count_;
}

/**
 * @brief 범위까지를 지우고 벨런스를 다시 잡는 역할
 * 
 * @param __first 
 * @param __last 
 */
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
void __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__erase_helper(const_iterator __first, const_iterator __last) {
	if (__first == begin() && __last == end())
		clear();
	for (; __first != __last; __first++)
		__erase_helper(__first);
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::size_type __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::erase(const key_type & __v) {
	ft::pair<const_iterator, const_iterator> __p = equal_range(__v);
	const size_type __prev_size = size();
	__erase_helper(__p.first, __p.second);
	return __prev_size - size();
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
void __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::swap(__tree & __t) {
	if (__root() == NULL) {
		if (__t.__root != NULL)
			__impl_.__tree_move_data(__t.__impl_);
	}
	else if (__t.__root() == NULL)
		__t.__impl_.__tree_move_data(__impl_);
	else {
		ft::swap(__root(), __t.__root());
		ft::swap(__leftmost(), __t.__leftmost());
		ft::swap(__rightmost(), __t.__rightmost());

		__root()->__parent_ = __end();
		__t.__root()->__parent_ = __t.__end();
		ft::swap(__impl_.__node_count_, __t.__impl_.__node_count_);
	}
	ft::swap(__get_Node_allocator(), __t.__get_Node_allocator());
}


/**
 * @brief 키 보다 같거나 큰 요소를 리턴한다. 
 * 
 * @param __x 시작 노드
 * @param __y 백업 노드
 * @param __k 비교할 키
 * @return __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator 
 */
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__lower_bound_helper(_Link_type __x, _Base_ptr __y, const key_type & __k) {
	while (__x != NULL) {
		if (!__impl_.__key_comp(__S_key(__x), __k)){
			__y = __x;
			__x = __S_left(__x);
		}
		else
			__x = __S_right(__x);
	}
	return iterator(__y);
}
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::const_iterator __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__lower_bound_helper(_Const_link_type __x, _Const_base_ptr __y, const key_type & __k) const {
	while (__x != NULL) {
		if (!__impl_.__key_comp(__S_key(__x), __k)){
			__y = __x;
			__x = __S_left(__x);
		}
		else
			__x = __S_right(__x);
	}
	return const_iterator(__y);
}

/**
 * @brief 키 보다 큰 요소를 리턴한다. 
 * 
 * @param __x 시작 노드
 * @param __y 백업 노드
 * @param __k 비교할 키
 * @return __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator 
 */
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__upper_bound_helper(_Link_type __x, _Base_ptr __y, const key_type & __k) {
	while (__x != NULL) {
		if (__impl_.__key_comp(__k, __S_key(__x))) {
			__y = __x;
			__x = __S_left(__x);
		}
		else
			__x = __S_right(__x);
	}
	return iterator(__y);
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::const_iterator __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::__upper_bound_helper(_Const_link_type __x, _Const_base_ptr __y, const key_type & __k) const {
	while (__x != NULL) {
		if (__impl_.__key_comp(__k, __S_key(__x))) {
			__y = __x;
			__x = __S_left(__x);
		}
		else
			__x = __S_right(__x);
	}
	return const_iterator(__y);
}

/**
 * @brief 컨테이너 안의 주어진 키를 포함하는 범위를 리턴해준다. 
 *			first: >= key , second: > key
 * 
 * @param __k 
 * @return ft::pair<typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator, typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator> 
 */
template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
ft::pair<typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator, typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::iterator> __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::equal_range(const key_type & __k) {
	_Link_type __x = __begin();
	_Base_ptr __y = __end();
	while (__x != NULL) {
		if (__impl_.__key_comp(__S_key(__x), __k))
			__x = __S_right(__x);
		else if (__impl_.__key_comp(__k, __S_key(__x))) {
			__y = __x;
			__x = __S_left(__x);
		}
		else { // __x의 키 가 __k
			_Link_type __x_up(__x);
			_Base_ptr __y_up(__y);
			__y = __x;
			__x = __S_left(__x);
			__x_up = __S_right(__x_up);
			return (ft::pair<iterator, iterator>(__lower_bound_helper(__x, __y, __k), __upper_bound_helper(__x_up, __y_up, __k)));
		}
	}
	return (ft::pair<iterator, iterator>(iterator(__y), iterator(__y)));
}

template <typename _Key, typename _Val, typename _KeyofValue, typename _Compare, typename _Alloc>
ft::pair<
	typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::const_iterator, typename __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::const_iterator> __tree<_Key, _Val, _KeyofValue, _Compare, _Alloc>::equal_range(const key_type & __k) const {
	_Const_link_type __x = __begin();
	_Const_base_ptr __y = __end();
	while (__x != NULL) {
		if (__impl_.__key_comp(__S_key(__x), __k))
			__x = __S_right(__x);
		else if (__impl_.__key_comp(__k, __S_key(__x))) {
			__y = __x;
			__x = __S_left(__x);
		}
		else { // __x의 키 가 __k
			_Const_link_type __x_up(__x);
			_Const_base_ptr __y_up(__y);
			__y = __x;
			__x = __S_left(__x);
			__x_up = __S_right(__x_up);
			return ft::pair<const_iterator, const_iterator>(__lower_bound_helper(__x, __y, __k), __upper_bound_helper(__x_up, __y_up, __k));
		}
	}
	return (ft::pair<const_iterator, const_iterator>(const_iterator(__y), const_iterator(__y)));
}

}; // namspace ft RBtree end 


#endif