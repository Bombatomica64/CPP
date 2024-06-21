/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:14:54 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/21 10:15:57 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), m_target("default")
{
	std::cout << *this << " was created" << std::endl;
	srandom(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) 
	: AForm("RobotomyRequestForm", 72, 45), m_target(target)
{
	std::cout << *this << " was created" << std::endl;
	srandom(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) 
	: AForm(other), m_target(other.m_target)
{
	std::cout << *this << " was created" << std::endl;
	srandom(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << *this << " was destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}


void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	int ran = random() % 2;

	if (ran == 0)
		std::cout << "Drilling noises... " << m_target << " has been robotomized" << std::endl;
	else
		std::cout << "Drilling noises... " << m_target << " robotomization failed" << std::endl;
}