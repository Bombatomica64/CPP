/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:39:49 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 13:11:14 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main ( void )
{
	ClapTrap Samu("Samu");
	ClapTrap Marco("Marco");

	Samu.attack("Marco");
	Marco.takeDamage(5);
	Marco.beRepaired(3);
	Marco.attack("Samu");
	Samu.takeDamage(50);
	Samu.takeDamage(50);
	
	ScavTrap lollo("Lollo");
	ScavTrap pippo("Pippo");

	lollo.attack("Pippo");
	pippo.takeDamage(20);
	pippo.guardGate();

	FragTrap io("io");
	FragTrap tu("tu");

	tu = io;
	tu.attack("io");
	io.takeDamage(20);
	tu.highFivesGuys();


	DiamondTrap gu("gu");
	DiamondTrap simo("simo");

	gu.attack("simo");
	simo.takeDamage(20);
	simo.whoAmI();

	gu = simo;

	return 0;
}