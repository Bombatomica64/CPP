/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATile.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:59:58 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 17:39:27 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATile.hpp"

ATile::ATile() : _next(NULL), _prev(NULL), _materia(NULL) {}

ATile::ATile(ATile const & copy)
{
	*this = copy;
}

ATile & ATile::operator=(ATile const & rhs)
{
	if (this != &rhs)
	{
		this->_next = rhs._next;
		this->_prev = rhs._prev;
		this->_materia = rhs._materia;
	}
	return *this;
}

ATile::~ATile() {
	if (this->_materia)
		delete this->_materia;

	if (this->_next)
		delete this->_next;

	if (this->_prev)
		delete this->_prev;
}

ATile*		ATile::getNext() const { return this->_next; }
ATile*		ATile::getPrev() const { return this->_prev; }
AMateria*	ATile::getMateria() const { return this->_materia; }

void		ATile::setNext(ATile* next) { this->_next = next; }
void		ATile::setPrev(ATile* prev) { this->_prev = prev; }
void		ATile::setMateria(AMateria* materia) { this->_materia = materia; }