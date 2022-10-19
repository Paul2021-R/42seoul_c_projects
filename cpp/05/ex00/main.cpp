/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:29:11 by haryu             #+#    #+#             */
/*   Updated: 2022/10/19 13:24:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat test("haryu", 150);
    std::cout << test << std::endl;

    test.increaseGrade(3);
    
    test.decreaseGrade(10);

    std::cout << test << std::endl;
    return 0;
}