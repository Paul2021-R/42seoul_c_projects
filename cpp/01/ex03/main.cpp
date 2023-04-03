/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:24:26 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 13:45:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	요구사항 
	- 웨폰
		- getter(상수 레퍼런스 타입 반환), setter(새로운 값으로 지정)
	- Human 공통 
		- name, 웨폰, attack()
	- HumanA 
		- 생성자 안에서 웨폰을 얻음
	- HumanB 
		- 생성자 안에서 웨폰을 항상 갖지 않음
*/

int main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spikde club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
