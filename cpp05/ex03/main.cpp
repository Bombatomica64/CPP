/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:19:10 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/21 10:15:57 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;

	AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
	AForm* robotomy = intern.makeForm("robotomy request", "home");
	AForm* presidential = intern.makeForm("presidential pardon", "home");

	AForm* not_found = intern.makeForm("insert AForm joke here", "home");

	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *presidential << std::endl;
	if (not_found)
		std::cout << *not_found << std::endl;
    return 0;
}