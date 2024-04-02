/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:06:34 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/02 17:54:27 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact created" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact destroyed" << std::endl;
}

Contact::Contact(const Contact& other)
{
	this->index = other.index;
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->nickname = other.nickname;
	this->phone_number = other.phone_number;
	this->darkest_secret = other.darkest_secret;
}

void	Contact::set_index(int index)
{
	this->index = index;
}

void	Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}
int	Contact::get_index()
{
	return (this->index);
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

