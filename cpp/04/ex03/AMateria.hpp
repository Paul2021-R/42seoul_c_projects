/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:20:47 by haryu             #+#    #+#             */
/*   Updated: 2022/10/14 05:12:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_hpp
# define AMateria_hpp

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class AMateria {
// protected:
// 	std::string type;
public:
	// AMateria(void);
	// AMateria(const std::string& type);
	// AMateria& operator=(const AMateria& target);
	virtual ~AMateria(void) {};

	const std::string& getType(void) const = 0;
	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);
};

class Ice : public AMateria {
private:
	std::string type;
public:
	Ice(void);
	Ice(const Ice& target);
	Ice& operator=(const Ice& target);
	~Ice(void);

	const std::string& getType(void) const;
	Ice* clone(void) const;
	void use(ICharacter& target);
};

class Cure : public AMateria {
private:
	std::string type;
public:
	Cure(void);
	Cure(const Cure& target);
	Cure& operator=(const Cure& target);
	~Cure(void);

	const std::string& getType(void) const;
	Cure* clone(void) const;
	void use(ICharacter& target);
};

#endif