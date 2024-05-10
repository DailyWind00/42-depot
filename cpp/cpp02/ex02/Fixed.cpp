/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:59 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/10 17:21:42 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Canonical Form :
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed( const Fixed &fixed )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed & Fixed::operator=( const Fixed &fixed )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
// ---



// Specifics Constructors :
Fixed::Fixed( int const toRawBits )
{
	// std::cout << "Int constructor called" << std::endl;
	this->rawBits = toRawBits << this->bits;
}

Fixed::Fixed( float const toRawBits )
{
	// std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(toRawBits * (1 << this->bits));
}
// ---



// Specifics Operators :
bool Fixed::operator>( const Fixed &fixed ) const
{
	return (this->rawBits > fixed.getRawBits());
}

bool Fixed::operator<( const Fixed &fixed ) const
{
	return (this->rawBits < fixed.getRawBits());
}

bool Fixed::operator>=( const Fixed &fixed ) const
{
	return (this->rawBits >= fixed.getRawBits());
}

bool Fixed::operator<=( const Fixed &fixed ) const
{
	return (this->rawBits <= fixed.getRawBits());
}

bool Fixed::operator==( const Fixed &fixed ) const
{
	return (this->rawBits == fixed.getRawBits());
}

bool Fixed::operator!=( const Fixed &fixed ) const
{
	return (this->rawBits != fixed.getRawBits());
}



Fixed Fixed::operator+( const Fixed &fixed ) const
{
	return(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-( const Fixed &fixed ) const
{
	return(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*( const Fixed &fixed ) const
{
	return(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/( const Fixed &fixed ) const
{
	if (fixed.getRawBits() == 0)
	{
		std::cout << "Cannot divide by 0 !\n";
		return -1;
	}
	return(this->toFloat() / fixed.toFloat());
}



Fixed Fixed::operator++( int )
{
	Fixed tmp = *this;
	this->rawBits++;
	return tmp;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp = *this;
	this->rawBits--;
	return tmp;
}

Fixed &Fixed::operator++( void )
{
	this->rawBits++;
	return *this;
}

Fixed &Fixed::operator--( void )
{
	this->rawBits--;
	return *this;
}
// ---

// Utility Functions :
int Fixed::toInt( void ) const
{
	return (this->rawBits >> this->bits);
}

float Fixed::toFloat( void ) const
{
	return (( float )this->rawBits / (1 << this->bits));
}



Fixed	&Fixed::min( Fixed &f1, Fixed &f2 )
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	&Fixed::max( Fixed &f1, Fixed &f2 )
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed 	&Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed		&Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
// ---



// Getters and Setters :
int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}
// ---



std::ostream & operator << ( std::ostream &os, const Fixed &fixed )
{
	os << fixed.toFloat();
	return (os);
}
