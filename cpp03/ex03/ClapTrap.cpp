/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:39:54 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 10:18:54 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : Name(name), Hitpoints(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << Name << " Awakens!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & rhs )
{
	*this = rhs;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs )
{
	Name = rhs.Name;
	Hitpoints = rhs.Hitpoints;
	Energy_points = rhs.Energy_points;
	Attack_damage = rhs.Attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " has taken too much damage! ....... Or just gave up!" << std::endl;
}

void ClapTrap::attack( std::string const & target )
{
	if (this->Energy_points == 0)
	{
		std::cout << "ClapTrap " << Name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << Name << " attacks " << target << " causing: " << this->Attack_damage << " points of damage" << std::endl;
	this->Energy_points--;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if (amount == 0)
	{
		std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
	Hitpoints -= amount;
	if (Hitpoints < 0)
	{
			Hitpoints = 0;
			std::cout << "ClapTrap " << Name << " has been destroyed!" << std::endl;
	}

}

void ClapTrap::beRepaired( unsigned int amount )
{
	if (Hitpoints == 10)
	{
		std::cout << "ClapTrap " << Name << " is already at full health!" << std::endl;
		return ;
	}
	else if (this->Energy_points == 0)
	{
		std::cout << "ClapTrap " << Name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << Name << " is being repaired for " << amount << " points!" << std::endl;
	Hitpoints += amount;
	if (Hitpoints > 10)
		Hitpoints = 10;
	this->Energy_points--;
}