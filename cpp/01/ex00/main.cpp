/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:45:13 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 01:50:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	std::string name;

	std::getline(std::cin, name);
	Zombie zomA(name);
	zomA.announce();
	Zombie* zomB;
	zomB = newZombie(name.append("alloc"));
	zomB->announce();
	delete zomB;
	randomChump(name.append("randomChump_case"));
	return 0;
}
