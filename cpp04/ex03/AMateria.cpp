/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:01:17 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/30 16:34:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria(AMateria const & copy) {
	*this = copy;
}

AMateria & AMateria::operator=(AMateria const & rhs) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::~AMateria() {

}

std::string const & AMateria::getType() const {
	return _type;
}