/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:20:16 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 07:43:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "./ex00 \"parameter\"" << std::endl;
		return 1;
	}
	convert	val(av[1]);
	std::cout << val << std::endl;
	std::cout << std::stod(av[1]) << std::endl;
	return 0;
}