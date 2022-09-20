/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randumChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:44:11 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 01:51:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie *target;

	target = newZombie(name);
	target->announce();
	delete target;
};

// 클래스 포인터 변수는 .이 아닌 -> 로 클래스 변수(함수)에 접근한다. 
