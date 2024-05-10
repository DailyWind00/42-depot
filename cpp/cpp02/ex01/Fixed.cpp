/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:59 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/10 14:32:05 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Canonical Form :
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed & Fixed::operator=( const Fixed &fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
// ---



// Specifics Constructors :
Fixed::Fixed( int const toRawBits )
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = toRawBits << this->bits;
}

Fixed::Fixed( float const toRawBits )
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(toRawBits * (1 << this->bits));
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
// ---



// Getters and Setters :
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}
// ---



std::ostream & operator << ( std::ostream &os, const Fixed &fixed )
{
	os << fixed.toFloat();
	return (os);
}
