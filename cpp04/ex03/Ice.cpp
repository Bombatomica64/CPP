/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:04:44 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/29 18:31:31 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {
}

Ice::Ice(Ice const & copy) : AMateria(copy) {

}

Ice & Ice::operator=(Ice const & rhs) {
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice() {

}

AMateria* Ice::clone() const {
	return new Ice(*this);
}