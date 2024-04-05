/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:20:08 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/05 10:43:26 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class	Harl
{
	public:
		Harl( void );
		Harl(const Harl &other);
		~Harl( void );

		void	complain( std::string level);
		
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif