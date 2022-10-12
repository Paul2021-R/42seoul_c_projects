/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:52 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 21:09:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>
#include <string>

class Animal {
// private: 
// 	std::string type;
public:
	// Animal(void): type("none"){}
	virtual ~Animal(void) {};
	// Animal(const Animal& target): type(target.type) {}
	// Animal& operator=(const Animal& target) {
	// 	type = target.type;
	// 	return *this;
	// }


    virtual void				makeSound(void) const = 0;
    virtual void				setIdeas(const std::string& idea) = 0;
	virtual void				setIdeas(const std::string& idea, int num) = 0;
	virtual void				showIdeas(void) = 0;
	virtual std::string&		getIdea(int num) = 0;
	virtual const std::string&	getType(void) const = 0;
	
};

#endif