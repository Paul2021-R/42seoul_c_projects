/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:29:11 by haryu             #+#    #+#             */
/*   Updated: 2022/10/19 19:27:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat test("haryu", 150);
    std::cout << test << std::endl;

    test.increaseGrade();
    
    test.decreaseGrade();
    test.decreaseGrade();
    test.decreaseGrade();
    for (int idx = 0; idx < 151; idx++)
        test.increaseGrade();

    std::cout << test << std::endl;
    std::cout << "Get Name : " << test.getName() << std::endl;
    std::cout << "Get Grade : " << test.getGrade() << std::endl;
    return 0;
}