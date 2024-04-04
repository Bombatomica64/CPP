/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:25:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/04 15:54:33 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		HumanA(const HumanA &other);
		~HumanA();
		void attack( void );
		Weapon &getWeapon( void );
		std::string getName( void );
	private:
		std::string name;
		Weapon &weapon;
};

#endif