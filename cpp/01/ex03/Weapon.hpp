/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:25:37 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 14:06:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	std::string type;
	
	public:
		Weapon(const char *str);
		const std::string& getType(void);
		void	setType(std::string newWeapon);
};

# define ATTACK " attacks with their ";

#endif 
