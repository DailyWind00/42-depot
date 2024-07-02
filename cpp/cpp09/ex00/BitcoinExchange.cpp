/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:49:06 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/02 18:47:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Private functions :
std::fstream	BTC::openFile( const char *path ) const
{
	std::fstream	file;

	file.open( path, std::ios::out );
	if ( !file.is_open() )
		throw CannotOpenFileException();
	return file;
}

size_t	BTC::convertDateToNumber( std::string date ) const
{
	
}

void	BTC::addToData( size_t date, float value )
{
	
}
// ---



// Canonical Form :
BTC::BTC()
{
}

BTC::BTC( const BTC &toCopy )
{
	*this = toCopy;
}

BTC & BTC::operator=( const BTC &toCopy )
{
	if ( this != &toCopy )
	{
		this->data = toCopy.data;
	}
	return *this;
}

BTC::~BTC()
{
}
// ---



// Public functions :
// ---




// Exceptions :
const char *BTC::CannotOpenFileException::what() const throw()
{
	return "Cannot open file.";
}

const char *BTC::InvalidDateFormatException::what() const throw()
{
	return "Invalid date format.";
}

const char *BTC::NegativeNumberException::what() const throw()
{
	return "Negative number.";
}

const char *BTC::TooLargeNumberException::what() const throw()
{
	return "Too large number.";
}
// ---