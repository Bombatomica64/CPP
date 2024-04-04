/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:36:22 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/04 15:44:49 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::HumanA(const HumanA &other) : name(other.name), weapon(other.weapon)
{
	this->name = other.name;
	this->weapon = other.weapon;
}

HumanA::~HumanA()
{
}

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}