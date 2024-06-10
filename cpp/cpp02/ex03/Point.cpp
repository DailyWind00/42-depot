/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dailywind <dailywind@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:13:56 by dailywind         #+#    #+#             */
/*   Updated: 2024/06/04 11:29:09 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Canonical Form :
Point::Point() : x(0), y(0) {}

Point::Point( const Point &point ) : x(point.x), y(point.y) {}

Point & Point::operator=( const Point &point )
{
	if (this == &point)
		return *this;
	Point tmp(point);
	return *this = tmp;
}

Point::~Point() {}
// ---



// Specifics Constructors :
Point::Point( Fixed posX, Fixed posY ) : x(posX), y(posY) {}
// ---



// Getters and Setters :
Fixed const		Point::getX( void ) const
{
	return (this->x);
}

Fixed const		Point::getY( void ) const
{
	return (this->y);	
}
// ---



// Function to check if a point is inside a triangle a b c
// The function returns true if the point is inside the triangle, false otherwise
// Algorythm used : https://www.youtube.com/watch?v=HYAgJN3x4GA
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	vectorX = (a.getX() * (c.getY() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY())) / ((b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()));
	Fixed	vectorY = (point.getY() - a.getY() - vectorX * (b.getY() - a.getY())) / (c.getY() - a.getY());

	std::cout << "vectorX: " << vectorX << std::endl;
	std::cout << "vectorY: " << vectorY << std::endl;
	if (vectorX < 0 || vectorY < 0 || vectorX + vectorY > 1)
	{
		std::cout << "Point outside the triangle\n\n";
		return false;
	}
	std::cout << "Point inside the triangle\n\n";
	return true;
}
