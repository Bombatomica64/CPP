/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:40:25 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 13:04:47 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private :
		FragTrap();

	public :
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs);
		FragTrap & operator=(FragTrap const & rhs);
		~FragTrap();
		void attack(std::string const & target);
		void highFivesGuys();
};

#endif