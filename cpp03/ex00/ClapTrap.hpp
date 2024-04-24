/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:39:51 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/24 18:18:10 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

	private:
		std::string Name;
		int Hitpoints;
		int Energy_points;
		int Attack_damage;

	public:
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & rhs );
		ClapTrap & operator=( ClapTrap const & rhs );
		~ClapTrap();
		void attack( std::string const & target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

};

#endif