/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:20:26 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 16:25:03 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog type constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog	&Dog::operator=(const Dog &obj) {
	std::cout << "Dog assignation operator called" << std::endl;
	this->SetType(obj.getType());
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Wouf wouf" << std::endl;
}