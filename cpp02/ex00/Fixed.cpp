/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:01:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/16 10:57:40 by lmicheli         ###   ########.fr       */
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
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}