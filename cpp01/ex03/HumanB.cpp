/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:36:08 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/04 16:14:11 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(weapon)
{
	this->name = name;
}

HumanB::HumanB(const HumanB &other) : name(other.name), weapon(other.weapon)
{
	this->name = other.name;
	this->weapon = other.weapon;
}

HumanB::~HumanB() {}

void HumanB::attack( void )
{
	std::string	type = this->weapon.getType();
	if (type != "")
		std::cout << this->name << " attacks with his " << type << std::endl;
	else
		std::cout << this->name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}