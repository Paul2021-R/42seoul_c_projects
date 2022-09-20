/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:46:07 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 02:14:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class  Zombie
{
private:
	std::string _name;

public:
	Zombie(void){
		_name = "";
	};
	Zombie(std::string name): _name(name){
	};
	Zombie(Zombie& copy) {
		_name = *(new std::string((copy._name)));
	};
	~Zombie(void) {
		std::cout << _name << " is destructed." << std::endl;
	};
	Zombie& operator=(Zombie& target) {
		size_t length = target._name.size();
		_name = target._name.substr(0, length);
		return *this;
	};
	void announce(void);
	void addName(std::string name);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif
