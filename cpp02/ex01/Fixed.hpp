/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:34:37 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/03 10:27:36 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed( const int value );
		Fixed( const float value );
		Fixed( const Fixed& other );
		~Fixed();
		Fixed& operator=( const Fixed& other );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int value;
		static const int bits = 8;

};

std::ostream& operator<<( std::ostream& os, const Fixed& value );

#endif