/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:24 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/06 15:25:56 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form() : m_name("default"), m_signed(false), m_gradeToSign(150), m_gradeToExecute(150)
{
	std::cout << *this << " was created" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) 
	: m_name(name), m_signed(false), m_gradeToSign(gradeToSign),
		 m_gradeToExecute(gradeToExecute)
{
	if (this->gradeCheck(gradeToSign) == -1)
		throw Form::GradeTooHighException();
	if (this->gradeCheck(gradeToExecute) == 1)
		throw Form::GradeTooLowException();
	std::cout << *this << " was created" << std::endl;
}

Form::Form(Form const &other) : m_name(other.m_name), m_signed(other.m_signed), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute)
{
	std::cout << *this << " was created" << std::endl;
}

Form::~Form()
{
	std::cout << *this << " was destroyed" << std::endl;
}

Form &Form::operator=(Form const &other)
{
	if (this == &other)
		return *this;
	m_signed = other.m_signed;
	return *this;
}

int Form::getGradeToSign() const
{
	return m_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return m_gradeToExecute;
}

std::string const &Form::getName() const
{
	return m_name;
}

bool Form::getSigned() const
{
	return m_signed;
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > m_gradeToSign)
		throw Form::GradeTooLowException();
	m_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName();
	out << " level :[" << form.getGradeToSign() << "] [";
	out << form.getGradeToExecute() << "]" << " is ";
	if (form.getSigned())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

int Form::gradeCheck(int grade) const
{
	if (grade < 1)
		return -1;
	if (grade > 150)
		return 1;
	return 0;
}