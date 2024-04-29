/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:04:48 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/29 18:05:50 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(Cure const & copy) : AMateria(copy) {

}

Cure & Cure::operator=(Cure const & rhs) {
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

Cure::~Cure() {

}

AMateria* Cure::clone() const {
	return new Cure(*this);
}