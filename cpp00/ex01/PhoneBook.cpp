/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:05:40 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/02 17:27:14 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed" << std::endl;	
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	
}

void	PhoneBook::add_contact()
{
	std::string	input;
	Contact		contact;
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contact.set_first_name(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contact.set_last_name(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contact.set_nickname(input);
	std::cout << "Enter login: ";
	std::getline(std::cin, input);
	contact.set_login(input);
	std::cout << "Enter postal address: ";
	std::getline(std::cin, input);
	contact.set_postal_address(input);
	std::cout << "Enter email address: ";
	std::getline(std::cin, input);
	contact.set_email_address(input);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contact.set_phone_number(input);
	std::cout << "Enter favorite meal: ";
	std::getline(std::cin, input);
	contact.set_favorite_meal(input);
	std::cout << "Enter underwear color: ";
	std::getline(std::cin, input);
	contact.set_underwear_color(input);
	std::cout << "Enter darkest secret";
	std::getline(std::cin, input);
	contact.set_darkest_secret(input);
	
}