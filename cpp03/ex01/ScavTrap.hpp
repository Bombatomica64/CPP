/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:30:04 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 11:09:43 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :
		std::string Name;
		int Hitpoints;
		int Energy_points;
		int Attack_damage;

	public :
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & rhs);
		ScavTrap & operator=(ScavTrap const & rhs);
		~ScavTrap();
		void attack(std::string const & target);
		void guardGate();
};