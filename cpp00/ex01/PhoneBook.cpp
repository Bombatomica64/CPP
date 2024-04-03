/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:05:40 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/03 18:34:12 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
	this->nb_contacts = 0;
	this->oldest = 0;
	std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed" << std::endl;	
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	this->nb_contacts = other.nb_contacts;
	for (int i = 0; i < 8; i++)
		this->contacts[i] = other.contacts[i];
}

void	PhoneBook::add_contact()
{
	std::string	input;
	Contact		contact;
	
	do
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		contact.set_first_name(input);
	}
	while (input.empty());
	
	do
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		contact.set_last_name(input);
	}
	while (input.empty());
	
	do
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		contact.set_nickname(input);
	}
	while (input.empty());
	
	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		contact.set_phone_number(input);
	}
	while (input.empty());
	
	do
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		contact.set_darkest_secret(input);
	}
	while (input.empty());
	
	if (this->nb_contacts < 8)
	{
		this->contacts[this->nb_contacts] = contact;
		this->nb_contacts++;
		contact.set_index(this->nb_contacts);
	}
	else
	{
		this->contacts[this->oldest] = contact;
		this->oldest = (this->oldest + 1) % 8;
	}
}

void	PhoneBook::search_contact()
{
	std::string	input;
	int			index;
	
	
	if (this->nb_contacts == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	displayContacts();

	while (true)
	{
	
	std::cout << "Enter index: ";
	std::cin >> input;
	std::istringstream ss(input);
	ss >> index;

	if (!(index < 1 || index > this->nb_contacts))
		break;
		std::cout << "Invalid index" << std::endl;
	}
	index--;
	
	std::cout << "First name: " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index].get_darkest_secret() << std::endl;
}

void PhoneBook::displayContacts()
{
	std::cout << "     Index | First name | Last name  | Nickname " << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	for (int i = 0; i < this->nb_contacts; i++)
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		std::string first_name = this->contacts[i].get_first_name();
		std::string last_name = this->contacts[i].get_last_name();
		std::string nickname = this->contacts[i].get_nickname();
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << " | ";
		std::cout << std::setw(10) << last_name << " | ";
		std::cout << std::setw(10) << nickname << std::endl;
	}
}
