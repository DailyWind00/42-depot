/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:53:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/08 09:48:23 by mgallais         ###   ########.fr       */
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
	return ( c == '+' || c == '-' || c == '*' || c == '/' );
}

bool	RPNCalculator::checkSyntax( std::string line ) const
{
	try
	{
		if ( line.size() <= 0 )
			throw RPNCalculator::EmptyArgumentException();
	
		char	previous_char = ' ';
		int		number_count = (bool)isdigit( line[0] );

		for (size_t i = 0; i < line.size(); i++)
		{
			std::cout << line[i] << " : " << previous_char << " : " << number_count << "\n";
			// Check if there is invalid characters
			if ( !isdigit(line[i]) && !isdigit(previous_char) && !isoperator(line[i]) )
				throw RPNCalculator::InvalidSyntaxException();

			// Check if the operator is not repeated
			if ( isoperator(line[i]) && isoperator(previous_char) )
				throw RPNCalculator::InvalidSyntaxException();

			// Check if the number is between 0 and 9
			if ( isdigit(line[i]) && isdigit(previous_char) )
				throw RPNCalculator::InvalidNumberException();

			// Check if the syntax respect the RPN notation
			if ( isdigit(line[i]) && number_count < 2 )
				number_count++;
			else if ( isoperator(line[i]) && number_count == 2)
				number_count--;
			else if ( !isspace(line[i]) )
				throw RPNCalculator::ImpossibleCalculationException();

			previous_char = line[i];
		}
		if ( number_count != 1 )
			throw RPNCalculator::ImpossibleCalculationException();

		std::cout << "Info: Syntax is correct\n";
		return true;
	}
	catch( const std::exception& e )
	{
		std::cerr << "Error: " << e.what() << '\n';
		return false;
	}
}
// ---



// Public Functions :
size_t	RPNCalculator::calculate( std::string line )
{
	if ( !checkSyntax(line) )
		return -1;
	try
	{
		int	j;
		int	k;
		for (size_t i = 0; i < line.size(); i++)
		{
			if ( isdigit(line[i]) )
				nums.push(line[i] - 48);
			
			if ( isoperator(line[i]) )
			{
				switch (line[i])
				{
					case '+':
						k = nums.top();
						nums.pop();
						j = nums.top();
						nums.pop();
						nums.push(k + j);
						break;
						
					case '-':
						k = nums.top();
						nums.pop();
						j = nums.top();
						nums.pop();
						nums.push(k - j);
						break;
					
					case '*':
						k = nums.top();
						nums.pop();
						j = nums.top();
						nums.pop();
						nums.push(k * j);
						break;

					case '/':
						k = nums.top();
						nums.pop();
						j = nums.top();
						nums.pop();
						if ( !j )
							throw DivisionByZeroException();
						nums.push(k / j);
						break;
				}
			}
		}
		
		return nums.top();
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