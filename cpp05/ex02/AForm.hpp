/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:29 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/06 10:37:48 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const m_name;
		bool m_signed;
		int const m_gradeToSign;
		int const m_gradeToExecute;

	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &other);
		~Form();

		Form &operator=(Form const &other);

		int 				getGradeToSign() const;
		int 				getGradeToExecute() const;
		std::string const	&getName() const;
		bool 				getSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);
		int gradeCheck(int grade) const;
		virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif