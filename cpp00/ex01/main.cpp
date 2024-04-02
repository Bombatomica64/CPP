/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:06:46 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/02 17:02:05 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook	pb;
	std::string	input;

	while (true)
	{
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			pb.add_contact();
		else if (input == "SEARCH")
			pb.search_contact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}