/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:07:09 by haryu             #+#    #+#             */
/*   Updated: 2022/10/05 18:24:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_hpp
#define ScavTrap_hpp

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public :
    ScavTrap(void);
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& target);
    ScavTrap& operator=(const ScavTrap& target);
    ~ScavTrap(void);

    void    attack(const std::string& target);
    void    takeDamage(Point_i amount);
    void    beRepaired(Point_i amount);

    void    guardGate(void);
    bool    initHitPoint(Point_i amount);
    bool    initAttackDamage(Point_i amount);
    bool    initEnergyPoint(Point_i amount);

    void    printConstructor(void);
};

#endif