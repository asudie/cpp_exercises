#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
	int _rawValue;
	static const int _fraction = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int n);
	Fixed(const float f);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits() const;
	void setRawBits( int const raw );

	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif