/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:56:19 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/14 13:10:30 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {

	private:
		T* m_array;
		unsigned int m_size;	

	public:
		Array();
		Array(unsigned int n);
		Array(Array const& src);
		~Array();

		Array& operator=(Array const& src);
		T& operator[](unsigned int i);

		unsigned int size() const;
		class OutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif