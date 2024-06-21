/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:59:32 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/21 10:15:57 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), m_target("default")
{
	std::cout << *this << " was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) 
	: AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
	std::cout << *this << " was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) 
	: AForm(other), m_target(other.m_target)
{
	std::cout << *this << " was created" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << *this << " was destroyed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::fstream file;
	std::string filename = m_target + "_shrubbery";

	file.open(filename.c_str(), std::ios::out);
	std::string tree = "	  /\\      \n     /\\*\\     \n    /\\O\\*\\    \n   /*/\\/\\/\\   \n  /\\O\\/\\*\\/\\  \n /\\*\\/\\*\\/\\/\\ \n/\\O\\/\\/*/\\/O/\\\n      ||      \n      ||      \n      ||      \n";
	file << tree;
	file.close();
	std::cout << "Shrubbery has been created in " << filename << std::endl;
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &AForm)
{
	out << "ShrubberyCreationForm " << AForm.getName() << " with grade to sign " << AForm.getGradeToSign() << " and grade to execute " << AForm.getGradeToExecute();
	return out;
}