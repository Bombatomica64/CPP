/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:25:27 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/21 10:15:57 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("default"), m_grade(150)
{
	std::cout << *this << " was created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : m_name(name)
{
	if (this->gradeCheck(grade) == -1)
		throw Bureaucrat::GradeTooHighException();
	if (this->gradeCheck(grade) == 1)
		throw Bureaucrat::GradeTooLowException();
	m_grade = grade;
	std::cout << *this << " was created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : m_name(other.m_name), m_grade(other.m_grade)
{
	std::cout << *this << " was created" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this->m_grade == other.m_grade)
		return *this;
	m_grade = other.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << *this << " was destroyed" << std::endl;
}

std::string const	&Bureaucrat::getName( void ) const
{
	return m_name;
}

int Bureaucrat::getGrade( void ) const
{
	return m_grade;
}

void Bureaucrat::incrementGrade( void )
{
	if (this->gradeCheck(m_grade - 1) == -1)
		throw Bureaucrat::GradeTooHighException();
	m_grade--;
}

void Bureaucrat::decrementGrade( void)
{
	if (this->gradeCheck(m_grade + 1) == 1)
		throw Bureaucrat::GradeTooLowException();
	m_grade++;
}

int Bureaucrat::gradeCheck(int grade) const
{
	if (grade < 1)
		return -1;
	if (grade > 150)
		return 1;
	return 0;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &AForm)
{
	AForm.beSigned(*this);
	std::cout << *this << " signs " << AForm << std::endl;
}

void Bureaucrat::executeForm(AForm const &AForm)
{
	AForm.execute(*this);
	std::cout << *this << " executes " << AForm << std::endl;
}