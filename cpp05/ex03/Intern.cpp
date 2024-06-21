/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:57 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/21 10:15:57 by lmicheli         ###   ########.fr       */
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

AForm* Intern::createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Did not find the AForm :";
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{

	std::map<std::string, AForm* (Intern::*)(std::string const &target)> form_map;
	form_map["shrubbery creation"] = &Intern::createShrubberyCreationForm;
    form_map["robotomy request"] = &Intern::createRobotomyRequestForm;
    form_map["presidential pardon"] = &Intern::createPresidentialPardonForm;
	try
	{
		if (form_map.find(name) != form_map.end())
		{
			std::cout << "Intern creates " << name << " AForm" << std::endl;
			return (this->*form_map[name])(target);
		}
		throw FormNotFoundException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << name << std::endl;
		return NULL;
	}
}