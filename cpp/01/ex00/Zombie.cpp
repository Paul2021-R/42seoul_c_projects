/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:09 by haryu             #+#    #+#             */
/*   Updated: 2022/09/17 18:51:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

Zombie* Zombie::newZombie(std::string name) {
	Zombie *target;

	target = new Zombie(name);
	return target;
}

void Zombie::randomChump(std::string name) {
	(void)name;
}