/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:05:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/14 17:55:06 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : N(n) {}

Span::Span(Span const& copy) : N(copy.N), v(copy.v) {}


Span& Span::operator=(Span const& copy)
{
	if (this == &copy)
		return *this;
	N = copy.N;
	v = copy.v;
	return *this;
}

Span::~Span() {}


void Span::addNumber(int n)
{
	if (v.size() >= N)
		throw Span::AlreadyFull();
	v.insert(std::lower_bound(v.begin(), v.end(), n), n);
}

unsigned int Span::shortestSpan()
{
	if (v.size() < 2)
		throw Span::NotEnoughNumbers();
	unsigned int i = 0, j = 1;
	unsigned int size = v.size();
	unsigned int currentSpan = v[j] - v[i];
	while (j < size)
	{
		if (static_cast<unsigned int>(std::abs(v[j] - v[i])) < currentSpan)
			currentSpan = v[j] - v[i];
		i++;
		j++;
	}
	return currentSpan;
}

unsigned int Span::longestSpan()
{
	if (v.size() < 2)
		throw Span::NotEnoughNumbers();
	return v[v.size() - 1] - v[0];
}


const char* Span::AlreadyFull::what() const throw()
{
	return "The container is already full";
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return "Not enough numbers to compute the span";
}