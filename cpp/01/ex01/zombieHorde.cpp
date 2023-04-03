/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:55:03 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 02:09:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) return NULL;
	
	Zombie* Horde;
	
	Horde = new Zombie[N];
	if (!Horde)
		return NULL;
	for (int idx = 0; idx < N; idx++) {
		Horde[idx].addName(name);
	}
	return Horde;
}
