/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:19:10 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 11:09:39 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;

	Form* shrubbery = intern.makeForm("shrubbery creation", "home");
	Form* robotomy = intern.makeForm("robotomy request", "home");
	Form* presidential = intern.makeForm("presidential pardon", "home");

	Form* not_found = intern.makeForm("insert form joke here", "home");

	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *presidential << std::endl;
	if (not_found)
		std::cout << *not_found << std::endl;
    return 0;
}