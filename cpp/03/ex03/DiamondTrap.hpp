/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:48:00 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 02:34:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_hpp
# define DiamondTrap_hpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string name;
		Point_i&	hitPoint;
		Point_i&	eneregyPoint;
		Point_i&	attackDamage;
	public:

	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& target);
	~DiamondTrap(void);
	DiamondTrap&	operator=(const DiamondTrap& target);

	void	attack(const std::string& target);

	void	whoAmI(void);
	void	printConstructor(std::string type);
};

#endif