/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:55 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 21:10:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "derived.hpp"
#include "Animal.hpp"

int main(){
	Animal* j = new Dog;
	Animal* i = new Cat;

	std::cout << "j type : " << j->getType() << " " << std::endl;
	std::cout << "i type : " << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();

	j->setIdeas("HELL YEAHHHH!!", 20);
	j->setIdeas("HELL YEAHHHH!!", 25);
	j->setIdeas("HELL YEAHHHH!!", 99);
	j->showIdeas();
	i->showIdeas();
	
	delete i;
	delete j;
	return 0;
}