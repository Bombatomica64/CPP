/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:39:10 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/05 11:18:26 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
	std::cout << "Harl is born!" << std::endl;
}

Harl::Harl(const Harl &other) {
	(void)other;
	std::cout << "Harl is cloned!" << std::endl;
}

Harl::~Harl( void ) {
	std::cout << "*Harl* : \"I don't feel so good...\"" << std::endl;
}

void	Harl::debug( void ) {
	std::cout << "*Harl* : \"Debugging your messy code...\"" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "*Harl* : \"I have some information for you...\"" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "*Harl* : \"Warning! Warning!\"" << std::endl;
}

void	Harl::error( void ) {
	std::cout << "*Harl* : \"Your code is a mess!\"" << std::endl;
}

void	Harl::complain( std::string level)
{
	int type = 0;

	for (int i = 0; i < level.size(); ++i)
	{
		type += level[i];
	}
	switch (type)
	{
	case 359:
		this->debug();
	case 300:
		this->info();
	case 534:
		this->warning();
	case 394:
		this->error();
		break;
	default:
		std::cerr << "Probably complaining about insignificant problem" << std::endl;
		break;
	}
}