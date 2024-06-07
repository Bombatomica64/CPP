/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:05:30 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 10:06:07 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>
#include <functional>


class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		~Intern();

		Intern &operator=(Intern const &other);

		Form	*makeForm(std::string const &name, std::string const &target);
		Form	*createShrubberyCreationForm(std::string const &target);
		Form	*createRobotomyRequestForm(std::string const &target);
		Form	*createPresidentialPardonForm(std::string const &target);
};

#endif