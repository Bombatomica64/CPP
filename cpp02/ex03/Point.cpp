/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:39 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/03 12:34:16 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0), real_x(0), real_y(0){
}

Point::Point(const Point& other) : x(other.x), y(other.y), real_x(other.real_x), real_y(other.real_y) {

}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y), real_x(x), real_y(y){

}

Point::~Point() {
}

Point& Point::operator=(const Point& other) {
	if (this == &other)
		return *this;
	(Fixed)this->x = other.x;
	(Fixed)this->y = other.y;
	this->real_x = other.real_x;
	this->real_y = other.real_y;
	return *this;
}

Fixed Point::getX() const {
	return real_x;
}

Fixed Point::getY() const {
	return real_y;
}

void Point::setX(Fixed const x) {
	this->real_x = x;
}

void Point::setY(Fixed const y) {
	this->real_y = y;
}