#ifndef Warlock_hpp
#define Warlock_hpp

#include <iostream>
#include <string>

class Warlock {
private:
	std::string name;
	std::string title;

	Warlock();
	Warlock(const Warlock& other);
	Warlock& operator=(const Warlock& other);

public:
	Warlock(std::string name, std::string title);
	~Warlock();

	// for constant Warlock -> need const
	const std::string& getName(void) const;
	const std::string& getTitle(void) const;

	void setTitle(const std::string& target);

	void introduce(void) const;
};

#endif