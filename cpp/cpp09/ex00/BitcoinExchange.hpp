/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:48:37 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/02 18:34:55 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BTC {
	private :
		/// Attributes :
		std::map<size_t, float> data;
		
		/// Private Functions :
		std::fstream	openFile( const char *path ) const;
		size_t	convertDateToNumber( std::string date ) const;
		void	addToData( size_t date, float value );
		
	public :
		/// Canonical Form :
		BTC();
		BTC( const BTC &toCopy );
		BTC & operator=( const BTC &toCopy );
		~BTC();
		
		/// Public Functions :
		void	getBitcoinDatabase( const char *path );
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

};