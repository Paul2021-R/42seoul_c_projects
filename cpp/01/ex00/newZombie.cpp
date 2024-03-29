/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:39:35 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 01:52:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie	*target;

	target = new Zombie(name);
	return target;
}
// 새로이 할당하는 클래스에 생성자를 활용하면 클래스 포인터에 새로이 클래스 포인터 변수를 할당 받을 수 있다.
