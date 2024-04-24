/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:39 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/24 12:12:03 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {

}

Point::Point(const Point& other) : x(other.x), y(other.y) {

}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y) {

}

Point::~Point() {
}

Point& Point::operator=(const Point& other) {
	if (this == &other)
		return *this;
	Fixed abscissa = other.getX();
	Fixed ordinate = other.getY();
	x = abscissa;
	y = ordinate;
	return *this;
}

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}