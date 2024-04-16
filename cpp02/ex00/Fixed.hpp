/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:34:37 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/16 10:02:05 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed( const Fixed& other );
		~Fixed();
		Fixed& operator=( const Fixed& other );
	
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int value;
		static const int bits = 8;

};


#endif