/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:14:15 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 18:31:26 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

class Serializer
{
	private:
		Serializer() {};
		Serializer(Serializer const &copy) {(void)copy;};
		Serializer &operator=(Serializer const &copy) {(void)copy; return *this;};
	public:
		~Serializer() {};
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);	
};

#endif