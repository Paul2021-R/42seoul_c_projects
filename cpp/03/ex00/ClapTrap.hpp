/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:27:33 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 00:14:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

typedef	unsigned int			Point_i;

class ClapTrap 
{
private:
	std::string 	name;
	Point_i			hitPoint;
	Point_i			energyPoint;
	Point_i			attackDamage;

public:
	//OCCF
	ClapTrap(void);
	ClapTrap(std::string name, Point_i hp, Point_i ep, Point_i ad);
	ClapTrap(ClapTrap &target);
	~ClapTrap(void);
	ClapTrap&	operator=(ClapTrap &target);

	/**
	 * @brief 활동 에너지를 관리하기 위한 멤버함수.
	 * 
	 * @return true 에너지 사용함
	 * @return false 에너지 사용 불가 
	 */
	bool	useEnergy(void);
	/**
	 * @brief 타겟을 지정된 데미지 만큼 공격하고, 활동한 것 만큼 에너지를 소비한다.
	 * 
	 * @param target 
	 */
	void	attack(const std::string& target);
	/**
	 * @brief 지정된 양만큼의 공격을 당한다. 
	 *
	 * @param amount 
	 */
	void	takeDamange(Point_i amount);
	/**
	 * @brief 지정된 양 만큼 회복한다. 
	 * @param amount 
	 */
	void	beRepaired(Point_i amount);

	bool	initHitPoint(Point_i amount);
	bool	initEnergyPoint(Point_i amount);
	bool	initAttackDamage(Point_i amount);
	bool	setName(std::string target);

	void	printConstructor(void);
};

#endif
