/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:53:30 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/08 10:24:52 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPNCalculator {
	private :
		/// Attributes :
		std::stack<size_t>	nums;

		/// Private Functions :
		bool	checkSyntax( std::string line ) const;
		bool	isoperator( int c ) const;

	public :
		/// Canonical Form :
		RPNCalculator();
		RPNCalculator( const RPNCalculator &toCopy );
		RPNCalculator & operator=( const RPNCalculator &toCopy );
		~RPNCalculator();
		
		/// Public Functions :
		size_t	calculate( std::string line );

		/// Exceptions :
		class InvalidSyntaxException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class EmptyArgumentException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class InvalidNumberException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class ImpossibleCalculationException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class DivisionByZeroException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};