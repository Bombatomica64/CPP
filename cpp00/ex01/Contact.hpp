/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:06:26 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/02 17:27:07 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		Contact();
		Contact(const Contact& other);
		~Contact();
		void	set_first_name(std::string first_name);
		void	set_last_name(std::string last_name);
		void	set_nickname(std::string nickname);
		void	set_login(std::string login);
		void	set_postal_address(std::string postal_address);
		void	set_email_address(std::string email_address);
		void	set_phone_number(std::string phone_number);
		void	set_favorite_meal(std::string favorite_meal);
		void	set_underwear_color(std::string underwear_color);
		void	set_darkest_secret(std::string darkest_secret);
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_login();
		std::string	get_postal_address();
		std::string	get_email_address();
		std::string	get_phone_number();
		std::string	get_favorite_meal();
		std::string	get_underwear_color();
		std::string	get_darkest_secret();

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	login;
		std::string	postal_address;
		std::string	email_address;
		std::string	phone_number;
		std::string	favorite_meal;
		std::string	underwear_color;
		std::string	darkest_secret;
};

#endif