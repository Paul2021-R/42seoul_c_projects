/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:36:08 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 14:14:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA 
{
private:
	std::string name;
	Weapon& WeaponA;

public:
	HumanA(std::string name, Weapon& Weapon);

	void	attack(void);
	void	setWeapon(Weapon Weapon);
	const std::string getName(void);
	Weapon& getWeapon(void);
};

#endif