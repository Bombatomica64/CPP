/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:39:49 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 11:11:46 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main ( void )
{
	// ClapTrap Samu("Samu");
	// ClapTrap Marco("Marco");

	// Samu.attack("Marco");
	// Marco.takeDamage(5);
	// Marco.beRepaired(3);
	// Marco.attack("Samu");
	// Samu.takeDamage(50);
	// Samu.takeDamage(50);
	
	ScavTrap lollo("Lollo");
	ScavTrap pippo("Pippo");

	lollo.attack("Pippo");
	pippo.takeDamage(50);

	return 0;
}