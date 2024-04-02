/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:06:34 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/02 17:27:31 by lmicheli         ###   ########.fr       */
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
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->nickname = other.nickname;
	this->login = other.login;
	this->postal_address = other.postal_address;
	this->email_address = other.email_address;
	this->phone_number = other.phone_number;
	this->favorite_meal = other.favorite_meal;
	this->underwear_color = other.underwear_color;
	this->darkest_secret = other.darkest_secret;
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

void	Contact::set_login(std::string login)
{
	this->login = login;
}

void	Contact::set_postal_address(std::string postal_address)
{
	this->postal_address = postal_address;
}

void	Contact::set_email_address(std::string email_address)
{
	this->email_address = email_address;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::set_favorite_meal(std::string favorite_meal)
{
	this->favorite_meal = favorite_meal;
}

void	Contact::set_underwear_color(std::string underwear_color)
{
	this->underwear_color = underwear_color;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
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

std::string	Contact::get_login()
{
	return (this->login);
}

std::string	Contact::get_postal_address()
{
	return (this->postal_address);
}

std::string	Contact::get_email_address()
{
	return (this->email_address);
}

std::string	Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string	Contact::get_birthday_date()
{
	return (this->birthday_date);
}

std::string	Contact::get_favorite_meal()
{
	return (this->favorite_meal);
}

std::string	Contact::get_underwear_color()
{
	return (this->underwear_color);
}

std::string	Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

