/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:01:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/24 12:07:09 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void printBits(int num) {
    for(int bit = sizeof(int) * 8 - 1; bit >= 0; bit--) {
        std::cout << ((num >> bit) & 1);
    }
    std::cout << std::endl;
}
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	value = 0;	
}

Fixed::Fixed( const Fixed& other )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
}
Fixed::Fixed( const int value )
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed( const float value )
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

std::ostream& operator<<( std::ostream& os, const Fixed& value )
{
	os << value.toFloat();
	//os << (value.getRawBits() >> 8) << "." << ((value.getRawBits() & 255) >> 8);
	return os;
}

float Fixed::toFloat( void ) const
{
	return (float)value / (float)(1 << bits);
}

int Fixed::toInt( void ) const
{
	return value >> bits;
}

Fixed& Fixed::operator++()
{
	this->value = this->getRawBits() + pow(2, bits);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value = this->getRawBits() + pow(2, bits);
	return tmp;
}

Fixed& Fixed::operator--( void )
{
	value = value - pow(2, bits);
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	value = value - pow(2, bits);
	return tmp;
}

bool Fixed::operator>( const Fixed& other ) const
{
	return (value > other.getRawBits());
}

bool Fixed::operator<( const Fixed& other ) const
{
	return (value < other.getRawBits());
}

bool Fixed::operator>=( const Fixed& other ) const
{
	return (value >= other.getRawBits());
}

bool Fixed::operator<=( const Fixed& other ) const
{
	return (value <= other.getRawBits());
}

bool Fixed::operator==( const Fixed& other ) const
{
	return (value == other.getRawBits());
}

bool Fixed::operator!=( const Fixed& other ) const
{
	return (value != other.getRawBits());
}



Fixed Fixed::operator+(const Fixed& other) const
{
	int firstInt;
	int secondInt;
	int firstDec;
	int secondDec;
	Fixed tmp;
	
	
	firstInt = (int)(this->getRawBits() >> bits);
	secondInt = (int)(other.getRawBits() >> bits);
	firstDec = (int)(this->getRawBits() & 255);
	secondDec = (int)(other.getRawBits() & 255);

	tmp = Fixed(firstInt + secondInt);
	tmp = tmp.getRawBits() >> bits;

	int64_t decPart = firstDec + secondDec;
	int64_t res = tmp.getRawBits() + decPart;
	Fixed tmp2;
	tmp2.setRawBits(res);
	return ((tmp2));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	int firstInt;
	int secondInt;
	int firstDec;
	int secondDec;
	Fixed tmp;

	firstInt = (int)(this->getRawBits() >> bits);	
	secondInt = (int)(other.getRawBits() >> bits);
	firstDec = (int)(this->getRawBits() & 255);
	secondDec = (int)(other.getRawBits() & 255);

	tmp = Fixed(firstInt - secondInt);
	tmp = tmp.getRawBits() >> bits;
	
	int64_t decPart = firstDec - secondDec;
	int64_t res = tmp.getRawBits() + decPart;
	Fixed tmp2;
	tmp2.setRawBits(res);
	return ((tmp2));
}

Fixed Fixed::operator/(const Fixed& other) const 
{
	if (other.getRawBits() == 0) {
		std::cerr << "Error: Division by zero." << std::endl;
		return Fixed();
	}
	long long normalizer = 1 << bits;
	// Convert to a larger fixed-point format to increase precision
	long long normalized_div = (long long)this->getRawBits() * normalizer;

	// Perform the division
	long long result = normalized_div / other.getRawBits();

	Fixed tmp;
	tmp.setRawBits(result);
	// Return the result as a new Fixed object
	return Fixed(tmp);
}

Fixed Fixed::operator*(const Fixed& other) const 
{
	int	firstInt;
	int	secondInt;
	int	firstDec;
	int	secondDec;
	Fixed tmp;
	// (fistInt + firstDec) * (secondInt + secondDec) = 
	//firstInt * secondInt + firstInt * secondDec + firstDec * secondInt + firstDec * secondDec
	firstInt = (int)(this->getRawBits() >> bits);
	secondInt = (int)(other.getRawBits() >> bits);
	firstDec = (int)(this->getRawBits() & 255);
	secondDec = (int)(other.getRawBits() & 255);
	tmp = Fixed(firstInt * secondInt);
	tmp = tmp.getRawBits() >> bits;
	
	int64_t decPart = firstInt * secondDec + firstDec * secondInt + firstDec * secondDec;
	int64_t res = tmp.getRawBits() + decPart;
	Fixed tmp2;
	tmp2.setRawBits(res);
	return ((tmp2));
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

Fixed::Fixed( std::string value )
{
	// std::cout << "String constructor called" << std::endl;
	std::stringstream iss(value);
	float tmp;
	iss >> tmp;
	if (iss.fail())
	{
		std::cerr << "Error: Invalid input." << std::endl;
		return ;
	}
	this->value = Fixed(tmp).getRawBits();

}