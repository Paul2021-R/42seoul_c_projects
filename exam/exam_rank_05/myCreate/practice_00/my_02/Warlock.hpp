#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "SpellBook.hpp"

#define OUT std::cout 
#define ENDL std::endl;

class Warlock {
private: 
	std::string name;
	std::string title;
	ASpell * mySpell;
	SpellBook learnedMySpell;


	Warlock();
	Warlock(const Warlock& other);
	Warlock& operator=(const Warlock& other);
public:
	Warlock(std::string name, std::string title);
	~Warlock();
	const std::string& getName() const;
	const std::string& getTitle() const;
	void setTitle(const std::string &val);
	void introduce() const;
	void learnSpell(ASpell * spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget& target);
};

#endif