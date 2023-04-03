/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:12:14 by haryu             #+#    #+#             */
/*   Updated: 2022/09/24 10:48:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "harl.hpp"

int main(int ac, char **av) {
	harl		harl;
	std::string	Command;

	if (ac != 2)
		return (1);
	Command.assign(av[1]);
	harl.complain(Command);
	return (0);
}