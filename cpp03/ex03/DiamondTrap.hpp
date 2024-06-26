/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:04:06 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 10:56:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		DiamondTrap();
		std::string Name;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & rhs);
		DiamondTrap & operator=(DiamondTrap const & rhs);
		~DiamondTrap();

		using ScavTrap::attack;
		void whoAmI();

};

#endif