/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:01:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/19 15:47:42 by lmicheli         ###   ########.fr       */
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
	this->value = this->getRawBits() + 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value = this->getRawBits() + 1;
	return tmp;
}

Fixed& Fixed::operator--( void )
{
	value = value - 1;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	value = value - 1;
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

}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed((int)(long long)this->value / other.value / (1 << bits));
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
	printBits((Fixed(10.1f)).getRawBits());
	firstInt = (int)(this->getRawBits() >> bits);
	secondInt = (int)(other.getRawBits() >> bits);
	firstDec = (int)(this->getRawBits() & 255);
	secondDec = (int)(other.getRawBits() & 255);
	tmp = Fixed(firstInt * secondInt);
	tmp = tmp.getRawBits() >> bits;
	
	int64_t decPart = firstInt * secondDec + firstDec * secondInt + firstDec * secondDec;
	int64_t res = tmp.getRawBits() + decPart;
	printBits(decPart);
	std::cout << "res: " << Fixed((int)res) << std::endl;
	Fixed tmp2;
	tmp2.setRawBits(res);
	printBits(tmp2.getRawBits());
	return ((tmp2));
	/* tmp = tmp + Fixed((firstInt * secondDec));
	
	printBits((firstInt * secondDec));
	tmp = tmp + Fixed((firstDec * secondInt));
	printBits((firstDec * secondInt));
	tmp = tmp + Fixed((firstDec * secondDec));
	printBits((firstDec * secondDec));
	 */
	//printBits(tmp.getRawBits());
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