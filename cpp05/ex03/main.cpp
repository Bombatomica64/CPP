/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:19:10 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/06 15:46:46 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat High("High", 1);
	Bureaucrat Low("Low", 150);

    // Test case 1: ShrubberyCreationForm
    try
	{
        ShrubberyCreationForm form("garden");
        // form.execute(Bureaucrat("John", 150));
        // form.execute(Bureaucrat("Jane", 137));
		High.executeForm(form);
		High.signForm(form);
		High.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr <<  GREEN"cacca pupu: " RESET <<e.what() << std::endl;
	}

    // Test case 2: RobotomyRequestForm
    try
	{
        RobotomyRequestForm form("robot");
        form.execute(Bureaucrat("John", 72));
        form.execute(Bureaucrat("Jane", 45));
    }
	catch (std::exception &e)
	{
		std::cerr <<  BLUE " lobotomizzati: " RESET << e.what() << std::endl;
	}

    // Test case 3: PresidentialPardonForm
    try
	{
        PresidentialPardonForm form("president");
        form.execute(Bureaucrat("John", 50));
        form.execute(Bureaucrat("Jane", 1));

    }
	catch (std::exception &e)
	{
		std::cerr << CYAN "presidente ? " RESET << e.what() << std::endl;
	}

    return 0;
}