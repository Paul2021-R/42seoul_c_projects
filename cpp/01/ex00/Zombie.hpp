/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:46:07 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 01:43:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class  Zombie
{
private:
	std::string name;

public:
	Zombie(void){
		name = "";
	};
	Zombie(std::string name): name(name){
	};
	Zombie(Zombie& copy) {
		name = *(new std::string((copy.name)));
	};
	~Zombie(void) {
		std::cout << name << " is destructed." << std::endl;
	};
	Zombie& operator=(Zombie& target) {
		size_t length = target.name.size();
		name = target.name.substr(0, length);
		return *this;
	};
	void announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);


#endif
