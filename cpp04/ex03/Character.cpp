/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:00:15 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 17:55:13 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Floor.hpp"

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			{delete _inventory[i];}
}


Character::Character( Character const & copy ) {
	*this = copy;
}

Character & Character::operator=( Character const & rhs ) {
	if (this->_name != rhs.getName())
		this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break;
		}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
	delete _inventory[idx];
	_inventory[idx] = NULL;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	ATile* tmp = new ATile();
	tmp->setMateria(_inventory[idx]);
	Pavement.pushTile(tmp);
	_inventory[idx] = NULL;
}