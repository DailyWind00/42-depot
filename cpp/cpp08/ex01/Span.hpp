/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:17:12 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/26 09:23:15 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

class Span {
	private :
		std::vector<int>	numbers;
		size_t				size;

	public :
		/// Canonical Form :
		Span();
		Span( const Span &toCopy );
		Span & operator=( const Span &toCopy );
		~Span();
		
		/// Specifics Constructors :
		Span( size_t N );
		
		/// Utility Function :
		void	addNumber( int num );
		void	addNumber( int *nums, size_t size );
		size_t	shortestSpan();
		size_t	longestSpan();
		void	clearSpan();

		/// Exceptions :
		class	NoTEnoughNumberStockedException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class	TooManyNumberStockedException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class	NoDistanceFoundException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};