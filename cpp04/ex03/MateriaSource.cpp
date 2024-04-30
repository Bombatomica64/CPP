/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:42:55 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/30 17:44:23 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_materia[i] = nullptr;
}

MateriaSource::MateriaSource (MateriaSource const & copy) {
	*this = copy;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materia[i])
				delete _materia[i];
			if (rhs._materia[i])
				_materia[i] = rhs._materia[i]->clone();
			else
				_materia[i] = nullptr;
		}
	}
	return *this;
}