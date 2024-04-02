/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:06:12 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/02 17:06:01 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		~PhoneBook();
	void	add_contact();
	void	search_contact();
	
	private:
		Contact	contacts[8];
		int		nb_contacts;
};

#endif