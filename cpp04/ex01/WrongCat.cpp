/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:04:21 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 17:09:02 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : Animal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : Animal(type) {
	std::cout << "WrongCat type constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	this->SetType(obj.getType());
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Chuuu Chuu" << std::endl;
}