/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:44:12 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 12:31:48 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\e[1;95mFragTrap\e[0m constructor called" << std::endl;
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs)
{
	std::cout << "\e[1;95mFragTrap\e[0m copy constructor called" << std::endl;
	*this = rhs;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "\e[1;95mFragTrap\e[0m assignation operator called" << std::endl;
	this->Name = rhs.Name;
	this->Hitpoints = rhs.Hitpoints;
	this->Energy_points = rhs.Energy_points;
	this->Attack_damage = rhs.Attack_damage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "\e[1;95mFragTrap\e[0m destructor called" << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap " << this->Name << " attack " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "\e[1;95mFragTrap\e[0m " << this->Name << " wants an high five!" << std::endl;
	std::string answer;
	std::getline(std::cin, answer);
	if (answer == "yes")
		std::cout << "\e[1;95mFragTrap\e[0m " << this->Name << " gives you an high five!" << std::endl;
	else
		std::cout << "\e[1;95mFragTrap\e[0m " << this->Name << " is sad" << std::endl;
}