/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:52 by haryu             #+#    #+#             */
/*   Updated: 2022/10/15 11:46:13 by haryu            ###   ########.fr       */
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
    const std::string&      	getType(void) const;
};

#endif