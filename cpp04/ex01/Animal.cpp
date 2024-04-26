/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:47 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 18:23:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
	this->brain = new Brain();
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal type constructor called" << std::endl;
	this->brain = new Brain();
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
	delete this->brain;
}

Animal::Animal(const Animal &obj) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal		&Animal::operator=(const Animal &obj) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = obj.type;
	this->brain = obj.brain;
	return *this;
}

std::string	Animal::getType() const {
	return this->type;
}

void	Animal::SetType(std::string type) {
	this->type = type;
}

void	Animal::makeSound() const {
	return ;
}
		