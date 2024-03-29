/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:24:38 by haryu             #+#    #+#             */
/*   Updated: 2022/10/15 11:51:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharacter_hpp
# define ICharacter_hpp

class ICharacter {
public:
	virtual 						~ICharacter(void) {}
	virtual std::string const &		getName() const = 0;
	virtual void					equip(AMateria* M) = 0;
	virtual void					unequip(int idx) = 0;
	virtual void					use(int idx, ICharacter& target) = 0;
	virtual void					printSlot(void) const = 0;
};

/////////////////////////////////////////////////////////////////////////////////////

class Character: public ICharacter {
private:
	std::string						name;
	AMateria**						slot;
	int								slotNum;
public:
									Character(void);
									Character(const std::string name);
									Character(const Character& target);
									~Character(void);
	Character&						operator=(const Character& target);

	std::string const & 			getName() const;
	void 							equip(AMateria* M);
	void 							unequip(int idx);
	void 							use(int idx, ICharacter& target);
	void 							printSlot(void) const;
};

#endif