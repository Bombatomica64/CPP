/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:01:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/16 18:28:31 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;	
}

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
}
Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	return os;
}

float Fixed::toFloat( void ) const
{
	return (float)value / (1 << bits);
}

int Fixed::toInt( void ) const
{
	return value >> bits;
}

Fixed& operator++( Fixed& value )
{
	value.setRawBits(value.getRawBits() + 1);
	return value;
}

Fixed operator++( Fixed& value, int )
{
	Fixed tmp(value);
	value.setRawBits(value.getRawBits() + 1);
	return tmp;
}