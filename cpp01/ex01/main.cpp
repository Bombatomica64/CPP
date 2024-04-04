/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:23:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/04 12:23:30 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void )
{
	Zombie* horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}