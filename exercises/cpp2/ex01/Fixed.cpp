#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->_rawValue = other._rawValue;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawValue;
}

void Fixed::setRawBits(int const raw){
	this->_rawValue = raw;
}


Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	_rawValue = n << _fraction;
}

Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	_rawValue = roundf(f * (1 << _fraction));
}

float Fixed::toFloat() const {
	return (float)_rawValue / (1 << _fraction);
}

int Fixed::toInt() const {
	return _rawValue >> _fraction;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}