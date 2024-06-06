/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:57 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/06 16:26:21 by lmicheli         ###   ########.fr       */
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

Form* Intern::makeForm(std::string const &name, std::string const &target)
{
	std::map<std::string, std::function<Form*(std::string const &target)>> formCreators = {
		{"shrubbery creation", [](std::string const &target) { return new ShrubberyCreationForm(target); }},
		{"robotomy request", [](std::string const &target) { return new RobotomyRequestForm(target); }},
		{"presidential pardon", [](std::string const &target) { return new PresidentialPardonForm(target); }}
	};

	auto it = formCreators.find(name);
	if (it != formCreators.end())
	{
		std::cout << "Intern creates " << name << " form" << std::endl;
		return it->second(target);
	}
	else
	{
		std::cout << "Intern can't create " << name << " form" << std::endl;
		return nullptr;
	}
}