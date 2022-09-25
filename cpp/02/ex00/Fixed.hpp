#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
	int 				FixedPointVal;
	static const int	fractionalBit = 8;
public: 
	Fixed(void);
	Fixed(const Fixed& target);
	Fixed& operator=(const Fixed& target);
	~Fixed(void);
	int		getRawBits(void) const;
//	int		getfractionalBit(void) const;
	void	setRawBits(int const raw);
};

#endif 
