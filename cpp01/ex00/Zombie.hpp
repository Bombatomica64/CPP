/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:35:16 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/04 12:00:28 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		Zombie(const Zombie& other);
		~Zombie();
		
		void announce( void );
		void setName(const std::string& newName);
		std::string getName( void ) const;

		private:
		std::string name;
		
};

Zombie* newZombie( std::string name );

void	randomChump( std::string name );

#endif