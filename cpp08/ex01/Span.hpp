/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:04:57 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/14 17:52:47 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> v;
		Span() {}

	public:
		Span(unsigned int n);
		Span(Span const& copy);
		Span& operator=(Span const& copy);
		~Span();

		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();

	public:
		class AlreadyFull : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NotEnoughNumbers : public std::exception
		{
			virtual const char* what() const throw();
		};
		template <typename InputIterator>
		void addRange(InputIterator first, InputIterator last);
};

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		addNumber(*first);
		++first;
	}
}

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#endif