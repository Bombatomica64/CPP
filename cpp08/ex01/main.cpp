/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:04:43 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/14 17:38:29 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <climits>
#include <ctime>

int main()
{
	srand(time(NULL));

	std::cout << RED "Basic tests" RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(5);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(17);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << GREEN "Test with 10000 numbers" RESET << std::endl;

	Span sp2 = Span(10000);
	for (int i = 0; i < 10000; i++)
		sp2.addNumber(rand() % 10000);
	
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << YELLOW "Test with 100000 numbers" RESET << std::endl;

	Span sp3 = Span(100000);
	for (int i = 0; i < 100000; i++)
		sp3.addNumber(rand() % 100000);

	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	std::cout << BLUE "Test with intmax numbers" RESET << std::endl;

	Span sp4 = Span(214748364);

	for (u_int64_t i = 0; i < INT_MAX; i++)
		sp4.addNumber(rand() % INT_MAX);

	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;
}