/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:00:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/24 10:50:21 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#pragma once

class Weapon
{
	public:
		Weapon(std::string type);
		Weapon(const Weapon &other);
		~Weapon();
		std::string& getType( void );
		void setType(std::string type);
	
	private:
		std::string type;
};

#endif