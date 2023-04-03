/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:48:00 by haryu             #+#    #+#             */
/*   Updated: 2022/10/08 02:21:41 by haryu            ###   ########.fr       */
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
		std::string type;
		Point_i&	hitPoint;
		Point_i&	energyPoint;
		Point_i&	attackDamage;
	public:

	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& target);
	~DiamondTrap(void);
	DiamondTrap&	operator=(const DiamondTrap& target);

	void		whoAmI(void);
	void		guardGate(void);
	void		highFiveGuys(void);

    void        attack(const std::string& target);
    void        takeDamage(Point_i amount);
    void        beRepaired(Point_i amount);

    bool        initHitPoint(Point_i amount);
    bool        initEnergyPoint(Point_i amount);
    bool        initAttackDamage(Point_i amount);
    bool        setName(std::string target);

	std::string&    getName(void){ return name; }
    std::string&    getType(void){ return type; }
    Point_i&        getHp(void){ return hitPoint; }
    Point_i&        getEp(void){ return energyPoint; }
    Point_i&        getAd(void){ return attackDamage; }
};

#endif