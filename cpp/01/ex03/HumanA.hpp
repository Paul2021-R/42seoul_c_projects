/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:36:08 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 03:10:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA 
{
private:
	std::string name;
	Weapon weaponA;

public:
	HumanA(std::string name, Weapon& Weapon);
	HumanA(HumanA &target);
	~HumanA(void);
	HumanA	&operator=(HumanA &target);

	void	attack(void);
	const std::string getName(void);
	const Weapon& HumanA::getWeapon(void);
};

#endif