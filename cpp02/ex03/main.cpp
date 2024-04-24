/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:00:37 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/24 12:51:52 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static bool	is_a_triangle(Point const a, Point const b, Point const c)
{
	Fixed check;

	check =	(c.getY() - b.getY()) / (c.getX() - b.getX()) * (a.getX() - c.getX()) + c.getY();

	if (check == a.getY())
		return false;
	return true;
}

int main ( void )
{
	Point  points[4];

	for (int i = 0; i < 4; i++) {
		std::cout << "Enter \033[32mx\033[0m for point " << i + 1 << ": ";
		float x;
		std::cin >> x;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
		std::cout << "Enter \033[34my\033[0m for point " << i + 1 << ": ";
		float y;
		std::cin >> y;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
		points[i] = Point(Fixed(x), Fixed(y));
	}

	if (!is_a_triangle(points[0], points[1], points[2])) {
		std::cout << "The points do not form a triangle" << std::endl;
		return 1;
	}

	if (bsp(points[0], points[1], points[2], points[3]) ) {
	std::cout << "The point is inside the triangle" << std::endl;
	}
	else {
	std::cout << "The point is outside the triangle" << std::endl;
	}
}