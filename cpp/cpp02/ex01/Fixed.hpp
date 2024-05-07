/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:37:42 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/07 16:25:58 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{
	private :
		int					rawBits;
		static const int	bits = 8;
	public :
		// Canonical Form :
		Fixed();
		Fixed( const Fixed &fixed );
		Fixed & operator=( const Fixed &fixed );
		~Fixed();
		
		// Utility function
		Fixed( int toRawBits );
		Fixed( float toRawBits );
		int		toInt( void ) const ;
		float	toFloat( void ) const ;
		
		/* Getters and Setters */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
std::ostream & operator << (std::ostream &os, const Fixed &fixed);

#endif