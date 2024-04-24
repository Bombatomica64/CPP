/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:00:37 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/24 12:09:41 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main ( void )
{
	Point  points[4];

	for (int i = 0; i < 4; i++) {
		std::cout << "Enter x for point " << i + 1 << ": ";
		float x;
		std::cin >> x;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
		std::cout << "Enter y for point " << i + 1 << ": ";
		float y;
		std::cin >> y;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
		points[i] = Point(Fixed(x), Fixed(y));
	}
}