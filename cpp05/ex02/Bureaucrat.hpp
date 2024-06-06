/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:20:01 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/06 10:44:23 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

class Form;

class Bureaucrat
{
	private:
		std::string const m_name;
		int m_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();

		void incrementGrade();
		void decrementGrade();

		std::string const	&getName() const;
		int 				getGrade() const;

		int gradeCheck(int grade) const;
		void signForm(Form &form);
		void executeForm(Form const &form);

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif