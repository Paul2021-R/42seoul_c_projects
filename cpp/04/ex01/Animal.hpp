/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:52 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 17:13:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
#define Animal_hpp

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
    Animal&	operator=(const Animal& target);
    
    virtual void        		makeSound(void) const;
    const std::string&	getType(void) const;
	virtual void	setIdeas(const std::string& idea) = 0;
	virtual void	setIdeas(const std::string& idea, int num) = 0;
	virtual void	showIdeas(void) = 0;
	virtual std::string&	getIdea(int num) = 0;
};

#endif