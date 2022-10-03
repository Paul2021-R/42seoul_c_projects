/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:06:51 by haryu             #+#    #+#             */
/*   Updated: 2022/10/03 17:57:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap n1;
	ClapTrap n2("paul", 20, 5, 5);
	ClapTrap n3(n2);

	n1 = n2;
	n2.attack("target");
	n2.takeDamange(100);
	n2.attack("target");
    return 0;
}
