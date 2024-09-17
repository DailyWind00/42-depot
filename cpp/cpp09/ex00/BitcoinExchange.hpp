/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:48:37 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/04 13:43:08 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <map>

class BTC {
	private :
		/// Attributes :
		std::map<size_t, float> database;

		/// Private Functions :
		std::ifstream	&openFile( const char *path ) const;
		size_t	convertDateToNumber( std::string date ) const;
		int		checkMonthDayNumber( int month, int year ) const;
		bool	checkLineFormat( std::string line, char limiter ) const;
		
	public :
		/// Canonical Form :
		BTC();
		BTC( const BTC &toCopy );
		BTC & operator=( const BTC &toCopy );
		~BTC();
		
		/// Public Functions :
		void	addBitcoinDatabase( const char *path );
		void	findBitcoinValue( const char *path ) const;

		/// Exceptions :
		class CannotOpenFileException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class InvalidDateFormatException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class NegativeNumberException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class TooLargeNumberException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class BadInputException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};