/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:53:30 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/04 10:14:19 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream> // stringstream
#include <stack>
#include <cstdlib>

class RPNCalculator {
	public :
		/// Canonical Form :
		RPNCalculator();
		RPNCalculator( const RPNCalculator &toCopy );
		RPNCalculator & operator=( const RPNCalculator &toCopy );
		~RPNCalculator();
		
		/// Public Functions :
		long	calculate( std::string line, bool verbose = false );

		/// Exceptions :
		class InvalidSyntaxException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class EmptyArgumentException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class TooManyArgumentsException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class DivisionByZeroException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};

bool	isoperator( int c );