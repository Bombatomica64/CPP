/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:42:32 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 11:13:23 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Yes! i'm \033[97mDiamondTrap\033[0m " << name << std::endl;
	this->Name = name;
	this->ClapTrap::Name = name + "_clap_name";

	FragTrap::Hitpoints = 100;
	ScavTrap::Energy_points = 50;
	ScavTrap::Attack_damage = 30;

}
DiamondTrap::DiamondTrap(DiamondTrap const & rhs) : ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "Copy constructor for \033[97mDiamondTrap\033[0m called" << std::endl;
	*this = rhs;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "Assignation operator for \033[97mDiamondTrap\033[0m called" << std::endl;
	this->Name = rhs.Name;
	this->Hitpoints = rhs.Hitpoints;
	this->Energy_points = rhs.Energy_points;
	this->Attack_damage = rhs.Attack_damage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[97mDiamondTrap\033[0m " << this->Name << " is dead" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << this->Name << " and my ClapTrap name is " << this->ClapTrap::Name << std::endl;
}