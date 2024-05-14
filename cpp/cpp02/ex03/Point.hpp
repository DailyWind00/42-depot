/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dailywind <dailywind@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:13:46 by dailywind         #+#    #+#             */
/*   Updated: 2024/05/14 21:48:34 by dailywind        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point{
	private :
		Fixed const x;
		Fixed const y;
	public :
		// Canonical Form :
		Point();
		Point( const Point &point );
		Point & operator=( const Point &point );
		~Point();
		
		// Specifics Constructors :
		Point( Fixed x, Fixed y );

		// Specifics Operators :
		
		// Utility Function :
		
		// Getters and Setters :
		Fixed const		getX( void ) const;
		Fixed const		getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif