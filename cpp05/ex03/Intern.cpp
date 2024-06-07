/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:57 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 10:52:26 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Form* Intern::createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string form_names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	Form* (Intern::*form_creators[3])(std::string const &target) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i])
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (this->*form_creators[i])(target);
		}
	}
}