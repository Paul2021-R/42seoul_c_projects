#include <algorithm>
#include <initializer_list>
#include <memory>

template <typename T, typename Allocator = std::allocator<T>>
class MyVector {
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* iterator;
	typedef const iterator const_iterator;
	typedef value_type& reference;
	typedef const reference const_reference;
	// using size_type = size_t;
    // using value_type = T;
    // using iterator = value_type*;
    // using const_iterator = const iterator;
    // using reference = value_type&;
    // using const_reference = const reference;
private:
	iterator data_	= nullptr;	// 벡터 상의 최초 요소
	iterator avail_	= nullptr;	// 벡터 상의 마지막 요소 
	iterator limit_	= nullptr;	// 할당된 메모리 
	Allocator alloc_;			// 메모리 할당을 위한 클래스? 메모리 할당을 다루기 위한 객체. 기본적으로 std::allocator를 활용함에 따라 할당 방식이 표준 클래스를 활용한다고 생각하면 된다. 

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);
	void create(std::initializer_list<value_type>);

	// 배열 안의 요소를 파괴하고 메모리 할당을 해제하는 요소 
	void destroy() noexcept;

	// push_back 을 위한 지원 함수 
	void grow();
	void unchecked_append(const T&);

	// Swapper 
	void swap(MyVector& rhs) noexcept {
		std::swap(data_, rhs.data_);
		std::swap(avail_, rhs.avail_);
		std::swap(limit_, rhs.limit_);
		std::swap(alloc_, rhs.alloc_);
	}
public:
	// 기본 생성자
	MyVector() { create(); }
	// explicit 오버로딩된 생성자 
	explicit MyVector(size_type n, const value_type& val = value_type()){ create(n, val); }
	// 오버로딩된 initialzer_list 를 사용한 생성자
	MyVector(std::initializer_list<value_type> l) { create(l); }
	// 복사 생성자
	MyVector(const MyVector& v) { create(v.begin(), v.end()); }

	// 복사 할당 연산자
	MyVector& operator=(const MyVector& v);
	// 이동 생성자 move constructor 
	MyVector(MyVector&& v) noexcept { swap(v); }
	// 이동 대입 연산자 move assignement operator
	MyVector& operator=(MyVector&& v) noexcept;

	// 소멸자
	~MyVector() noexcept { destroy(); }
	// operator [] non const
	T& operator[](size_type i) { return data_[i]; }
	// const operator [] const
	const T& operator[] (size_type i) const { return data_[i]; }
	void push_back(const T& t) {
		if (avail_ == limit_)
			grow();
		unchecked_append(t);
	}
	// push a value emplace back
	template <typename ... Args>
	void emplace_back(Args&& ... args) {
		if (avail_ == limit_)
			grow();
		unchecked_append(value_type{args...});
	}
	// size
	size_type size() const { return avail_ - data_; }
	// begin no const
	iterator begin() { return data_; }
	// bigin const
	const_iterator begin() const { return data_; }
	// end no const 
	iterator end() { return avail_; }
	// end const
	const_iterator end() const { return avail_; }
	// clear
	void clear() { destroy(); }
	// is empty
	bool empty() const { return data_ == avail_; }
};

template <typename T, typename Allocator>
void MyVector<T, Allocator>::create() {
	data_ = avail_ = limit_ = 0;
}

template <typename T, typename Allocator>
void MyVector<T, Allocator>::create(size_type n, const T& val) {
	data_ = alloc_.allocate(n);
	limit_ = avail_ = data_ + n;
	std::uninitialized_fill(data_, limit_, val);
}

template <typename T, typename Allocator>
void MyVector<T, Allocator>::create(const_iterator i, const_iterator j) {
	data_ = alloc_.allocate(j - i);
	limit_ = avail_ = std::uninitialized_copy(i, j, data_);
}

template <typename T, typename Allocator>
void MyVector<T, Allocator>::create(std::initializer_list<value_type> l) {
	data_ = alloc_.allocate(l.size());
	limit_ = avail_ = std::uninitialized_copy(l.begin(), l.end(), data_);
}

template <typename T, typename Allocator>
void  MyVector<T, Allocator>::destroy() noexcept {
	if (data_) {
#if (__cplusplus < 202000)
		iterator it = avail_;
		while (it != data_) {
			alloc_.destroy(--it); // deprecated in C++17, removed in C++20
		}
#else
	std::destroy(data_, avail_);
#endif
	alloc_.deallocate(data_, limit_ - data_);
	}
	data_ = limit_ = avail_ = 0;
}

template<typename T, typename Allocator>
void MyVector<T, Allocator>::grow() {
	// 내용 증가가 필요하면, 현재 사용 양의 두배가 는다
	size_type new_size = std::max(2 * (limit_ - data_), ptrdiff_t(1));
	iterator new_data_ = alloc_.allocate(new_size);
	iterator new_avail_ = std::uninitialized_copy(data_, avail_, new_data_);
	destroy();
	data_ = new_data_;
	avail_ = new_avail_;
	limit_ = data_ + new_size;
}

template <typename T, typename Allocator>
void MyVector<T, Allocator>::unchecked_append(const T& val) {
#if (__cplusplus < 202000)
	alloc_.construct(avail_++, val);
#else
	std::construct_at(avail_++, val);
#endif
}

template <typename T, typename Allocator>
MyVector<T, Allocator>& MyVector<T, Allocator>::operator=(const MyVector<T, Allocator>& rhs) {
	if (&rhs != this) {
		destroy();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}


template <typename T, typename Allocator>
MyVector<T, Allocator>& MyVector<T,Allocator>::operator=(MyVector<T, Allocator>&& v) noexcept {
	if (this != &v) {
		MyVector temp(std::move(v));
		swap(temp);
	}
	return *this;
}

/*                main                  */

#include <string>
#include <iterator>
#include <iostream>

template<typename Container>
void printContainer(const Container& c, std::ostream& stream = std::cout) {
	typedef typename Container::value_type value_type;
	std::copy(c.begin(), c.end(), std::ostream_iterator<value_type>(stream, " "));
	stream << std::endl;
}

int main() {

	MyVector<int> vecint1;

	for (int i = 0; i < 10; i++)
		vecint1.push_back(i);
	printContainer(vecint1);

	// MyVector<char> vecchar2;
	// for (int i = 42; i < 52; i++) 
	// 	vecchar2.emplace_back(static_cast<char>(i));
	// printContainer(vecchar2);

	MyVector<char> vecChar2;
    // insert data using emplace_back
    for (int i = 0; i < 10; i++) 
		vecChar2.emplace_back(static_cast<char>(i + 'a'));
    printContainer(vecChar2);

	MyVector<int> vecInt3(5, 8);
	printContainer(vecInt3);

	MyVector<std::string> vecStr1 {"a", "b", "c"};
	printContainer(vecStr1);
	vecStr1.push_back("hello world");
	printContainer(vecStr1);

	MyVector<std::string> vecStr2 {"d", "e", "f"};

	MyVector<std::string>vecStr3(move(vecStr1));

	std::cout << "vec 1 : ";
	printContainer(vecStr1);
	std::cout << "vec 2 : "; 
	printContainer(vecStr2);
	std::cout << "vec 3 : ";
	printContainer(vecStr3);

	return EXIT_SUCCESS;
}