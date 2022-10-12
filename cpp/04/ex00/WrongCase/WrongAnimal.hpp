/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:09 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 15:34:01 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_hpp
#define WrongAnimal_hpp

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;	
public:
	Animal(void);
	Animal(const std::string& target);

	Animal(const Animal& target);
	virtual ~Animal(void);
	Animal& operator=(const Animal& target);

	void	makeSound(void) const ;
	const std::string& getType() const ;

};

#endif