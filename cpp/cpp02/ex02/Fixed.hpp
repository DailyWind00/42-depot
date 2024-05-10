/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:37:42 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/10 15:56:16 by mgallais         ###   ########.fr       */
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
		
		// Specifics Constructors :
		Fixed( int const toRawBits );
		Fixed( float const toRawBits ); 

		// Specifics Operators :
		bool operator>( const Fixed &fixed ) const;
		bool operator<( const Fixed &fixed ) const;
		bool operator>=( const Fixed &fixed ) const;
		bool operator<=( const Fixed &fixed ) const;
		bool operator==( const Fixed &fixed ) const;
		bool operator!=( const Fixed &fixed ) const;
		
		Fixed operator+( const Fixed &fixed ) const;
		Fixed operator-( const Fixed &fixed ) const;
		Fixed operator*( const Fixed &fixed ) const;
		Fixed operator/( const Fixed &fixed ) const;
		
		Fixed operator++( int );
		Fixed operator--( int );
		Fixed &operator++( void );
		Fixed &operator--( void );
 
		// Utility Function :
		int		toInt( void ) const ;
		float	toFloat( void ) const ;
	
		static	Fixed &min( Fixed &f1, Fixed &f2 );
		static	Fixed &max( Fixed &f1, Fixed &f2 );
		static const	Fixed &min( const Fixed &f1, const Fixed &f2 );
		static const	Fixed &max( const Fixed &f1, const Fixed &f2 );
		
		// Getters and Setters :
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
std::ostream & operator << (std::ostream &os, const Fixed &fixed);

#endif