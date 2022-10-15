/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:20:47 by haryu             #+#    #+#             */
/*   Updated: 2022/10/15 11:50:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_hpp
# define AMateria_hpp

#include "master.hpp"

class ICharacter;

class AMateria {
public:
	virtual						~AMateria(void) {}

	virtual const std::string&	getType(void) const = 0;
	virtual AMateria*			clone(void) const = 0;
	virtual void				use(ICharacter& target) = 0;
};

/////////////////////////////////////////////////////////////////////////////////////

class Ice : public AMateria {
private:
	std::string 				type;
public:
								Ice(void);
								Ice(const Ice& target);
	Ice&						operator=(const Ice& target);
								~Ice(void);

	const std::string&			getType(void) const;
	AMateria* 			å	å	clone(void) const;
	void 						use(ICharacter& target);
};

/////////////////////////////////////////////////////////////////////////////////////

class Cure : public AMateria {
private:
	std::string 				type;
public:
								Cure(void);
								Cure(const Cure& target);
	Cure& 						operator=(const Cure& target);
								~Cure(void);
	
	const std::string& 			getType(void) const;
	AMateria* 					clone(void) const;
	void 						use(ICharacter& target);
};

/////////////////////////////////////////////////////////////////////////////////////

#endif