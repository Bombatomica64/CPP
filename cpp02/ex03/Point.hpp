/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:35 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/03 12:32:05 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		Fixed real_x;
		Fixed real_y;

	public:
		Point();
		Point(const Point& other);
		Point(Fixed const x, Fixed const y);
		~Point();
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;
		void setX(Fixed const x);
		void setY(Fixed const y);

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif