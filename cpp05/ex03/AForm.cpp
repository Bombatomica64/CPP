/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:24 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/21 10:15:57 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : m_name("default"), m_signed(false), m_gradeToSign(150), m_gradeToExecute(150)
{
	std::cout << *this << " was created" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) 
	: m_name(name), m_signed(false), m_gradeToSign(gradeToSign),
		 m_gradeToExecute(gradeToExecute)
{
	if (this->gradeCheck(gradeToSign) == -1)
		throw AForm::GradeTooHighException();
	if (this->gradeCheck(gradeToExecute) == 1)
		throw AForm::GradeTooLowException();
	std::cout << *this << " was created" << std::endl;
}

AForm::AForm(AForm const &other) : m_name(other.m_name), m_signed(other.m_signed), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute)
{
	std::cout << *this << " was created" << std::endl;
}

AForm::~AForm()
{
	std::cout << *this << " was destroyed" << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
	if (this == &other)
		return *this;
	m_signed = other.m_signed;
	return *this;
}

int AForm::getGradeToSign() const
{
	return m_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return m_gradeToExecute;
}

std::string const &AForm::getName() const
{
	return m_name;
}

bool AForm::getSigned() const
{
	return m_signed;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > m_gradeToSign)
		throw AForm::GradeTooLowException();
	m_signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	out << "AForm " << AForm.getName();
	out << " level :[" << AForm.getGradeToSign() << "] [";
	out << AForm.getGradeToExecute() << "]" << " is ";
	if (AForm.getSigned())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed";
}

int AForm::gradeCheck(int grade) const
{
	if (grade < 1)
		return -1;
	if (grade > 150)
		return 1;
	return 0;
}