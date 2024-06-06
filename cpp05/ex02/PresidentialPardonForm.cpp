/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:44:35 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/06 12:27:27 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: Form("PresidentialPardonForm", 25, 5), m_target("default")
{
	std::cout << *this << " was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) 
	: Form("PresidentialPardonForm", 25, 5), m_target(target)
{
	std::cout << *this << " was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) 
	: Form(other), m_target(other.m_target)
{
	std::cout << *this << " was created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << *this << " was destroyed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this == &other)
		return *this;
	Form::operator=(other);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	if (!this->isSigned())
		throw Form::FormNotSignedException();
	std::cout << m_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}