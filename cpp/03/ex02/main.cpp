/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:06:51 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 01:36:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
	- occf
		- 생성
		- 소멸 
		- 복사 생성 
		- 복사 할당 
	- attack (n 회차) -> 마지막엔 활동이 불가능 해야한다. (EP = 0)
	- takeDamage -> 완전히 못 움직일 때까지 반복  (EP = 0)
	- attack 1 회 못 움직임 점검
	- EP 회복 (EP = 10)(system 권한)
	- beRepaired 진행 : 1 회차 에는 작동 안함(hp = 0)
	- HP 1 회복 (system 권한)
	- beRepaired 가능 
	- attack 1회 움직일 수 있고, 다시 활동 가능해짐을 
*/

int main(void) {
	// occf test
	FragTrap n1("Dragon");
	FragTrap n3(n1);
	FragTrap n4;
	n4 = n1;
	

	n1.initEnergyPoint(10);
	
	// Attack & Energy TEST
	for (int idx = 0; idx <= 10; idx++) {
		n1.attack("sand bag");
	}
	
	// takeDamage 
	for (int idx = 0; idx <= 5; idx++) {
		n1.takeDamage(30);
	}

	// HP = 0 case
	n1.attack("sand bag");
	n1.initEnergyPoint(10);
	n1.beRepaired(10);

	// HP forcely recovered/
	n1.initHitPoint(1);
	// beRepairing is okay
	n1.beRepaired(10);
	n1.attack("sand bag");

	n1.initAttackDamage(1000);
	n1.setName("Charlee");

	n1.highFiveGuys();
    return 0;
}
