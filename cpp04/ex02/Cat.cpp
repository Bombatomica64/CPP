/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:16:58 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/07 11:29:20 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat type constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &obj) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat	&Cat::operator=(const Cat &obj) {
	std::cout << "Cat assignation operator called" << std::endl;
	this->SetType(obj.getType());
	this->brain = new Brain(*obj.getBrain());
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Nyaa nyaa" << std::endl;
}