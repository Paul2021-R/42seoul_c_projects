/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:52 by haryu             #+#    #+#             */
/*   Updated: 2022/10/10 20:40:29 by haryu            ###   ########.fr       */
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
    
    virtual void        makeSound(void) const;
    virtual const std::string& getType(void) const;
};

class Dog : public Animal {
public:
    Dog(void);
    Dog(const Dog& target);
    ~Dog(void);
    Dog&	operator=(const Dog& target);

    void    makeSound(void) const;
    const std::string& getType(void) const;
};

// class Cat : public Animal { 
// public:
//     Cat(void);
//     Cat(const Cat& target);
//     ~Cat(void);
//     Cat&	operator=(const Cat& target);

//     void    makeSound(void);
//     std::string& getType(void) ;
// };
#endif