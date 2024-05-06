/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:46:55 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 17:08:03 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : _head(NULL) {}

Floor::Floor(Floor const & copy)
{
	*this = copy;
}

Floor& Floor::operator=(Floor const & rhs)
{
	if (this != &rhs)
	{
		this->_head = rhs._head;
	}
	return *this;
}

Floor::~Floor()
{
	while (this->_head)
		this->popTile();
	delete this->_head;
}

void Floor::pushTile(ATile* tile)
{
	if (!this->_head)
	{
		this->_head = tile;
		tile->setNext(NULL);
		tile->setPrev(NULL);
	}
	else
	{
		tile->setNext(this->_head);
		this->_head->setPrev(tile);
		this->_head = tile;
	}
}

void Floor::popTile()
{
	ATile* tmp = this->_head;
	if (this->_head->getNext())
	{
		this->_head = this->_head->getNext();
		this->_head->setPrev(NULL);
	}
	else
		this->_head = NULL;
	delete tmp;
}