/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:53:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/04 10:15:12 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Canonical Form :
RPNCalculator::RPNCalculator()
{
}

RPNCalculator::RPNCalculator( const RPNCalculator &toCopy )
{
	*this = toCopy;
}

RPNCalculator & RPNCalculator::operator=( const RPNCalculator &toCopy )
{
	(void)toCopy;
	return *this;
}

RPNCalculator::~RPNCalculator()
{
}
// ---



// Private Functions :
bool isoperator( int c )
{
	return ( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' );
}
// ---



// Public Functions :
long	RPNCalculator::calculate( std::string line, bool verbose )
{
	try
	{
		if ( verbose )
			std::cout << "╮ " << std::endl;

		if ( line.empty())
			throw EmptyArgumentException();
		
		std::stack<ssize_t>	nums; // container stack LIFO
		std::stringstream	ss(line);

		while ( ss.good() ) {
			std::string	tmp;
			ss >> tmp;

			if ( tmp.empty() )
				continue;
			if ( tmp.size() != 1)
				throw InvalidSyntaxException();

			if ( isdigit(tmp[0]) ) {
				nums.push( std::atoi(tmp.c_str()) );
			}
			else if ( isoperator(tmp[0]) && nums.size() >= 2 ) {

				ssize_t	b = nums.top(); nums.pop();
				ssize_t	a = nums.top(); nums.pop();
				
				if ( tmp[0] == '+' ) {
					nums.push( a + b );
				}
				else if ( tmp[0] == '-' ) {
					nums.push( a - b );
				}
				else if ( tmp[0] == '*' ) {
					nums.push( a * b );
				}
				else if ( tmp[0] == '/' ) {
					if ( b == 0 )
						throw DivisionByZeroException();
					nums.push( a / b );
				}
				else if ( tmp[0] == '%' ) {
					if ( b == 0 )
						throw DivisionByZeroException();
					nums.push( a % b );
				}
				
				if ( verbose )
					std::cout << "│ " << a << " " << tmp[0] << " " << b << " = " << nums.top() << std::endl;
			}
			else {
				throw InvalidSyntaxException();
			}
		}
		
		if ( nums.size() != 1 )
			throw TooManyArgumentsException();

		if ( verbose )
			std::cout << "╯ " << std::endl;
		return nums.top();
	}
	catch( const std::exception& e )
	{
		std::cerr << "│ Error: " << e.what() << '\n';
		if ( verbose )
			std::cerr << "╯ " << std::endl;
		return -1;
	}
}
// ---



// Exceptions :
const char *RPNCalculator::InvalidSyntaxException::what() const throw()
{
	return "Invalid syntax";
}

const char *RPNCalculator::EmptyArgumentException::what() const throw()
{
	return "Empty argument";
}

const char *RPNCalculator::TooManyArgumentsException::what() const throw()
{
	return "Too many arguments at the end of the calculation";
}

const char *RPNCalculator::DivisionByZeroException::what() const throw()
{
	return "Tried to divide by zero";
}
// ---