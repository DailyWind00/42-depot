/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:26:59 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 16:08:33 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Canonical Form :
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter &toCopy )
{
	*this = toCopy;
}

ScalarConverter & ScalarConverter::operator=( const ScalarConverter &toCopy )
{
	(void)toCopy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}
// ---



// Utility Function :
void	ScalarConverter::convert( const std::string &toConvert )
{
	std::cout << "> Convert " << toConvert << std::endl;
	int 	 	intConversion = atoi(toConvert.c_str());
	double		doubleConversion = strtod(toConvert.c_str(), NULL);
	
	// char
	std::cout << "char: ";
	if (intConversion < 0 || intConversion > 255 || (intConversion == 0 && toConvert != "0"))
		std::cout << "Impossible\n";
	else if (!std::isprint(intConversion))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(intConversion) << "'\n";
	// ---


	// int
	std::cout << "int: ";
	if (intConversion == 0 && toConvert != "0")
		std::cout << "Impossible\n";
	else
		std::cout << intConversion << std::endl;
	// ---


	// float
	std::cout << "float: ";
	if (doubleConversion == 0 && toConvert != "0")
		std::cout << "Impossible\n";
	else
		std::cout << static_cast<float>(doubleConversion) << "f" << std::endl;
	// ---
	

	// double
	std::cout << "double: ";
	if (doubleConversion == 0 && toConvert != "0")
		std::cout << "Impossible\n";
	else
		std::cout << doubleConversion << std::endl;
	// ---
	
	std::cout << std::endl;
}
// ---