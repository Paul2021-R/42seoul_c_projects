/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:40:32 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 14:12:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
# define HUMAN_B

# include "Weapon.hpp"

class HumanB 
{
private:
	std::string	name;
	Weapon*		WeaponB;

public:
	HumanB(std::string name);
	HumanB(HumanB &target);
	
	void	attack(void);
	void	setWeapon(Weapon& Weapon);
	const std::string getName(void);
	Weapon& getWeapon(void);
};

#endif