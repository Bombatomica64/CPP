/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:33:42 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 12:31:34 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Wait no! i'm \033[34mScavTrap\033[0m " << name << std::endl;
	this->Hitpoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	std::cout << "Wait no! i'm \033[34mScavTrap\033[0m " << Name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs)
{
	std::cout << "Copy constructor for \033[34mScavTrap\033[0m called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "Assignation operator for \033[34mScavTrap\033[0m called" << std::endl;
	this->Name = rhs.Name;
	this->Hitpoints = rhs.Hitpoints;
	this->Energy_points = rhs.Energy_points;
	this->Attack_damage = rhs.Attack_damage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[34mScavTrap\033[0m " << this->Name << " is dead" << std::endl;
}

void ScavTrap::attack( std::string const & target )
{
	std::cout << "\033[34mScavTrap\033[0m " << this->Name << " attacks " << target << " causing " << this->Attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "\033[34mScavTrap\033[0m " << this->Name << " has entered Gate keeper mode" << std::endl;
}