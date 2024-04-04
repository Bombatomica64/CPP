/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:28:32 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/04 15:54:19 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		HumanB(const HumanB &other);
		~HumanB();
		void attack( void );
		void setWeapon(Weapon &weapon);
		Weapon &getWeapon( void );
	private:
		std::string name;
		Weapon &weapon;
};

#endif