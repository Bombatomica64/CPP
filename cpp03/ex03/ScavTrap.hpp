/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:30:04 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:23 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private :
		ScavTrap();

	public :
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & rhs);
		ScavTrap & operator=(ScavTrap const & rhs);
		~ScavTrap();
		void attack(std::string const & target);
		void guardGate();
};

#endif