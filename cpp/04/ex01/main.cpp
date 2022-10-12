/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:55 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 18:23:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "derived.hpp"

int main(){
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j type : " << j->getType() << " " << std::endl;
	std::cout << "i type : " << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();

	Dog* k = new Dog();
	Cat* l = new Cat();

	Dog& temp = *k;
	Cat& temp2 = *l;

	Animal** arr = new Animal*[20];
	for (int idx = 0; idx < 20; idx++) {
		if (idx % 2 == 0) {
			arr[idx] = new Dog(temp);
		}
		else
			arr[idx] = new Cat(temp2);
	}

	for (int idx = 0; idx < 6; idx++) {
		std::cout << "Animal : " << idx << std::endl;
		arr[idx]->makeSound();
		if (idx % 2 == 0)
			arr[idx + 1]->setIdeas("This is custom idea");
		arr[idx]->showIdeas();
	}
	for (int idx = 0; idx < 20; idx++) {
		delete arr[idx];
	}
	delete i;
	delete j;
	delete[] arr;
	return 0;
}