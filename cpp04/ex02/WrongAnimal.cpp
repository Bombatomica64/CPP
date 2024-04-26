/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:58:05 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 17:02:36 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal		&WrongAnimal::operator=(const WrongAnimal &obj) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->type = obj.type;
	return *this;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

void	WrongAnimal::SetType(std::string type) {
	this->type = type;
}

void	WrongAnimal::makeSound() const {
	return ;
}