/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derived.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:19:06 by haryu             #+#    #+#             */
/*   Updated: 2022/10/15 11:48:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef derived_hpp
#define derived_hpp

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "brain.hpp"


class Dog : public Animal {
private:
	std::string				type;
	Brain*					myBrain;
public:
    Dog(void);
    Dog(const Dog& target);
    ~Dog(void);
    Dog&					operator=(const Dog& target);

    void					makeSound(void) const ;
	void					setIdeas(const std::string& idea);
	void					setIdeas(const std::string& idea, int num);
	void					showIdeas(void);
	std::string&			getIdea(int num);
	const std::string&		getType(void) const { return type; }
};

class Cat : public Animal { 
private:
	std::string				type;
	Brain*					myBrain;
public:
    Cat(void);
    Cat(const Cat& target);
    virtual ~Cat(void);
    Cat&					operator=(const Cat& target);

	void				    makeSound(void) const;
	void					setIdeas(const std::string& idea);
	void					setIdeas(const std::string& idea, int num);
	void					showIdeas(void);
	std::string&			getIdea(int num);
	const std::string&		getType(void) const { return type; }
};

#endif