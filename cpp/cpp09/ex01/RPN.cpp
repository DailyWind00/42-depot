/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:53:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/22 11:43:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Canonical Form :
RPNCalculator::RPNCalculator() : nums()
{
}

RPNCalculator::RPNCalculator( const RPNCalculator &toCopy ) : nums(toCopy.nums)
{
}

RPNCalculator & RPNCalculator::operator=( const RPNCalculator &toCopy )
{
	if ( this == &toCopy )
		return *this;
	nums = toCopy.nums;
	return *this;
}

RPNCalculator::~RPNCalculator()
{
}
// ---



// Private Functions :
bool RPNCalculator::isoperator( int c ) const
{
	return ( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' );
}
// ---



// Public Functions :
long	RPNCalculator::calculate( std::string line )
{
	try
	{
		if ( line.empty())
			throw EmptyArgumentException();
		
		std::stringstream	ss(line);

		while ( ss.good() )
		{
			std::string	tmp;
			ss >> tmp;

			if ( tmp.empty() )
				continue;

			if ( tmp.size() > 1 || (tmp[0] < '0' || tmp[0] > '9') )
			{
				if ( tmp.size() > 1 || !isoperator(tmp[0]) )
					throw InvalidSyntaxException();
				if ( nums.size() < 2 )
					throw ImpossibleCalculationException();

				size_t	n1 = nums.top(); nums.pop();
				size_t	n2 = nums.top(); nums.pop();

				switch (tmp[0])
				{
					case '+':
						nums.push(n1 + n2);
						break;
					case '-':
						nums.push(n2 - n1);
						break;
					case '*':
						nums.push(n1 * n2);
						break;
					case '/':
						if (n1 == 0)
							throw DivisionByZeroException();
						nums.push(n2 / n1);
						break;
					case '%':
						if (n1 == 0)
							throw DivisionByZeroException();
						nums.push(n2 % n1);
						break;
					default:
						throw InvalidNumberException();
				}
				nums.push(tmp[0] - '0');
			}
		}
	}
	catch( const std::exception& e )
	{
		std::cerr << "Error: " << e.what() << '\n';
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

const char *RPNCalculator::InvalidNumberException::what() const throw()
{
	return "Number must be between 0 and 9";
}

const char *RPNCalculator::ImpossibleCalculationException::what() const throw()
{
	return "Does not respect RPN notation";
}

const char *RPNCalculator::DivisionByZeroException::what() const throw()
{
	return "Tried to divide by zero";
}
// ---