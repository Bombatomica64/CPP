/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:03:35 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/24 11:36:20 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;


	public:
		Point();
		Point(const Point& other);
		Point(Fixed const x, Fixed const y);
		~Point();
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif