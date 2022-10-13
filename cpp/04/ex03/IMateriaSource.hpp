/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:25:59 by haryu             #+#    #+#             */
/*   Updated: 2022/10/14 05:17:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMateriaSource_hpp
# define IMateriaSource_hpp

#include <string>
#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource(void);
	virtual void learnMateria(AMateria* M) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
private:
	AMateria**	slot;
	int 		slotNum;
	
public: 
	MateriaSource(void);
	MateriaSource(const MateriaSource& target);
	MateriaSource& operator=(const MateriaSource& target);

	~MateriaSource(void);
	void learnMateria(AMateria* M);
	AMateria* createMateria(std::string const & type);
};
#endif