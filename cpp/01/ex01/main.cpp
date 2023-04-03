/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:09:39 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 02:13:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* horde;
	std::string name;

	getline(std::cin, name);
	horde = zombieHorde(5, name);
	for (int idx = 0; idx < 5; idx++) {
		horde[idx].announce();
	}
	delete[] horde;
	return 0;
}
