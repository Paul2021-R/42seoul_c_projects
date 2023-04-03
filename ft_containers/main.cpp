/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:52:45 by haryu             #+#    #+#             */
/*   Updated: 2022/12/29 16:53:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>
#include <ctime>

#define OUT std::cout
#define END	std::endl

#ifndef STDMODE 
#define STDMODE 0
#endif

#if STDMODE //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
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


int main(int argc, char** argv) {

#if STDMODE
	std::cout << "Standard Templete Library mode container program" << std::endl;
#else
	std::cout << "Custom Standard Templete Library mode container program" << std::endl;
#endif 

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << END;
		std::cerr << "Provide a seed please" << END;
		std::cerr << "Count value:" << COUNT << END;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	time_t firstTime;
	time_t secondTime;

	time(&firstTime);
	OUT << "Starting Time : " << firstTime << END;
	OUT << "\n===========================================================" << END;
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{

		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<END;
		}
	}
	catch(const std::exception& e)
	{ 	//NORMAL ! :P 
	}
	
	for (int i = 0; i < COUNT; ++i)
		map_int.insert(ft::make_pair(rand(), rand()));

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	OUT << "should be constant with the same seed: " << sum << END;
	{
		ft::map<int, int> copy(map_int);
	}
	MutantStack<char> iterable_stack;

	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
		OUT << *it << END;

	ft::set<char> setTest;
	for(MutantStack<char>::iterator nit = iterable_stack.begin(); nit != iterable_stack.end(); nit++)
	{
		setTest.insert(*nit);
	}
	OUT << "set size : " << setTest.size() << END;
	OUT << "set capacity : " << setTest.max_size() << END;
	OUT << "===========================================================\n" << END;
	time(&secondTime);
	OUT << "Finished Time : " << secondTime << END;
	OUT << "Container performance Gap : " << secondTime - firstTime << END;


#if DG && STDMODE
	OUT << "<<Leaks Test STL Library>>" << END;
	system("leaks -list std_container");
#elif DG
	OUT << "<<Leaks Test ft Library>>" << END;
	system("leaks -list ft_container");
#else
	OUT << "normarl main program finished" << END;
#endif

	return (0);
}
