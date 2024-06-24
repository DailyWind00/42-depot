/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:26:59 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 14:33:10 by mgallais         ###   ########.fr       */
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
	std::cout << "Convert " << toConvert << std::endl;
	std::cout << "Char : " << charConvertion( toConvert ) << std::endl;
	std::cout << "Int : " << intConvertion( toConvert ) << std::endl;
	std::cout << "Float : " << floatConvertion( toConvert ) << std::endl;
	std::cout << "Double : " << doubleConvertion( toConvert ) << std::endl;
	std::cout << std::endl;
}
// ---