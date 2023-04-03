/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derived.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:19:06 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 15:34:37 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef derived_hpp
#define derived_hpp

#include <iostream>
#include <string>
#include "Animal.hpp"


class Dog : public Animal {
public:
    Dog(void);
    Dog(const Dog& target);
    ~Dog(void);
    Dog&	operator=(const Dog& target);

    void	makeSound(void) const ;
};

class Cat : public Animal { 
public:
    Cat(void);
    Cat(const Cat& target);
    ~Cat(void);
    Cat&	operator=(const Cat& target);

	void    makeSound(void) const;
};

#endif