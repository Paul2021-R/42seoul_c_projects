/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:52:45 by haryu             #+#    #+#             */
/*   Updated: 2022/12/28 18:49:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>
#include <ctime>

#ifndef STDMODE 
#define STDMODE 0
#endif

#if STDMODE //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif


#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this = rhs;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};


int main_internal(int argc, char** argv) {

#if STDMODE
	printf("Standard Templete Library mode container program\n");
#else
	printf("Custom Standard Templete Library mode container program\n");
#endif 

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::map<int, int> map_int;

	time_t firstTime;
	time_t secondTime;

	time(&firstTime);
	std::cout << "Starting Time : " << firstTime << std::endl;
	std::cout << "\n===========================================================" << std::endl;
	
	for (int i = 0; i < COUNT; ++i)
		map_int.insert(ft::make_pair(rand(), rand()));

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;
	{
		ft::map<int, int> copy(map_int);
	}
	std::cout << std::endl;
	std::cout << "===========================================================\n" << std::endl;
	time(&secondTime);
	std::cout << "Finished Time : " << secondTime << std::endl;
	std::cout << "Container performance Gap : " << secondTime - firstTime << std::endl;

	return (0);
}

int main(int argc, char **argv)
{
	int result = main_internal(argc, argv);

#if DG && STDMODE
	system("leaks -list std_container");
#elif DG
	system("leaks -list ft_container");
#else
	std::cout << "normal mode testing" << std::endl;
#endif

	return result;
}
