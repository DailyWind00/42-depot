/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:02:42 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/26 09:23:19 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical Form :
Span::Span() : size(0)
{
}

Span::Span( const Span &toCopy )
{
	*this = toCopy;
}

Span & Span::operator=( const Span &toCopy )
{
	if (this == &toCopy)
		return *this;
	numbers = toCopy.numbers;
	size = toCopy.size;
	return *this;
}

Span::~Span()
{
}
// ---



// Specifics Constructors :
Span::Span( size_t N ) : size(N)
{
}
// ---



// Utility Function :
void	Span::addNumber( int num )
{
	if (numbers.size() >= size)
		throw TooManyNumberStockedException();

	numbers.push_back(num);
}

void	Span::addNumber( int *nums, size_t size )
{
	if (numbers.size() + size > this->size)
		throw TooManyNumberStockedException();
	
	numbers.insert(numbers.end(), nums, nums + size);
}

size_t	Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw NoTEnoughNumberStockedException();

	std::sort(numbers.begin(), numbers.end());
	std::vector<int> distances;
	for (size_t i = 1; i < numbers.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (i == j)
				continue;
			distances.push_back(std::abs(numbers[i] - numbers[j]));
		}
	}

	if (distances.empty())
		throw NoDistanceFoundException();
		
	return *std::min_element(distances.begin(), distances.end());
}

size_t	Span::longestSpan()
{
	if (numbers.size() < 2)
		throw NoTEnoughNumberStockedException();

	std::sort(numbers.begin(), numbers.end());
	return numbers.back() - numbers.front();
}

void	Span::clearSpan()
{
	numbers.clear();
}
// ---



// Exceptions :
const char *Span::NoTEnoughNumberStockedException::what() const throw()
{
	return "No number stocked";
}

const char *Span::TooManyNumberStockedException::what() const throw()
{
	return "Too many numbers stocked";
}

const char *Span::NoDistanceFoundException::what() const throw()
{
	return "No distance found";
}
// ---