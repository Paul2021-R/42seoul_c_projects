#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "vector.hpp"

namespace ft {

	template<class T, class Container = ft::vector<T> >
	class stack {

	public:
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

	protected:
		container_type	c;

	public:
		explicit stack(const Container& cont = Container()) : c(cont) {};

		~stack() {};

		stack& operator=(const stack& other) {
			c = other.getC();
			return *this;
		}

		reference top() {
			return c.back();
		}

		const_reference top() const {
			return c.back();
		}

		bool empty() const {
			return c.empty();
		}

		size_type size() const {
			return c.size();
		}

		void push(const value_type& value) {
			c.push_back(value);
		}

		void pop() {
			c.pop_back();
		}

		container_type getC() const { return this->c; }
	};

	template< class T, class Container >
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return lhs.getC() == rhs.getC();
	}

	template< class T, class Container >
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(lhs == rhs);
	}

	template< class T, class Container >
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return lhs.getC() < rhs.getC();
	}

	template< class T, class Container >
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(rhs < lhs);
	}

	template< class T, class Container >
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return rhs < lhs;
	}

	template< class T, class Container >
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(lhs < rhs);
	}

}

#endif
