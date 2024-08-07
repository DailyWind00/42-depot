/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:49:06 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/22 11:44:32 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Private functions :
std::ifstream	&BTC::openFile( const char *path ) const
{
	static std::ifstream	file;

	file.open( path, std::ios::in );
	if ( !file.is_open() )
		throw CannotOpenFileException();
	return file;
}

size_t	BTC::convertDateToNumber( std::string date ) const
{
	size_t	convertion = 0;
	
	/// Convertion : string YYYY-MM-DD to size_t YYYYMMDD
	// std::cout << "===" << date << "\n";
	convertion += atoi(date.substr(0, 4).c_str()) * 10000;
	convertion += atoi(date.substr(6, 7).c_str()) * 100;
	convertion += atoi(date.substr(8).c_str());
	// std::cout << ">> convertion" << "\n\n";
	
	return convertion;
}

int	BTC::checkMonthDayNumber( int month, int year ) const
{
	if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
		return 31;
	else if ( month == 4 || month == 6 || month == 9 || month == 11 )
		return 30;
	else if ( month == 2 && year % 4 )
		return 28;
	else
		return 29;
}

bool BTC::checkLineFormat(std::string line, char limiter) const
{
	/// Date parsing
	if ( line[4] != '-' || line[7] != '-' )
		return false;
	if ( atoi(line.substr(0, 4).c_str()) < 2009 || atoi(line.substr(0, 4).c_str()) > 2100 )
		return false;
	if ( atoi(line.substr(5, 7).c_str()) > 12 || atoi(line.substr(5, 7).c_str()) < 1 )
		return false;

	int year = atoi(line.substr(0, 4).c_str());
	int month = atoi(line.substr(5, 7).c_str());
	int day = atoi(line.substr(8, 10).c_str());

	if ( day < 1 || day > checkMonthDayNumber(month, year) )
		return false;

	/// Limiter and value parsing
	if ( limiter == ',' )
	{
		if ( line[10] != limiter )
			return false;
		if ( strtof(line.substr(11).c_str(), NULL) == 0 && line[11] != '0' )
			return false;
		if ( strtof(line.substr(11).c_str(), NULL) < 0 )
			return false;
		return true;
	}
	else if ( limiter == '|' )
	{
		if ( line[10] != ' ' && line[11] != limiter && line[12] != ' ' )
			throw BTC::BadInputException();
		if ( strtof(line.substr(12).c_str(), NULL) == 0 && line[11] != '0' )
			throw BTC::BadInputException();
		if ( strtof(line.substr(12).c_str(), NULL) < 0 )
			throw BTC::NegativeNumberException();
		if ( strtof(line.substr(12).c_str(), NULL) > 1000 )
			throw BTC::TooLargeNumberException();
		return true;
	}
	return false;
}
// ---



// Canonical Form :
BTC::BTC()
{
}

BTC::BTC( const BTC &toCopy )
{
	*this = toCopy;
}

BTC & BTC::operator=( const BTC &toCopy )
{
	if ( this != &toCopy )
	{
		database = toCopy.database;
	}
	return *this;
}

BTC::~BTC()
{
}
// ---



// Public functions :
void	BTC::addBitcoinDatabase( const char *path )
{
	std::cout << "Info: Loading database : " << path << "\n";
	try
	{
		std::ifstream &databaseFile = openFile( path );
		size_t	i = 0;
		size_t	j = 0;
		
		for (std::string line; std::getline(databaseFile, line); ) 
		{
			i++;
			
			if ( !checkLineFormat(line, ',') )
				continue;

			size_t	date = convertDateToNumber(line.substr(0, 10));
			float	value = atof(line.substr(11).c_str());
			
			std::cout << "New map node : date = " << date << " | value = " << value << "\r";
			usleep(150);
			j++;

			database.insert(std::pair<size_t, float>(date, value));
		}

		std::cout << "| " << i << " datas received                                  \n";
		std::cout << "| " << j << " datas accepted                                  \n";
		std::cout << "| > " << i - j << " datas lost                                \n";

		databaseFile.close();
	}
	catch( const std::exception& e )
	{
		std::cerr << "> Error: " << e.what() << '\n';
	}
	
}

void	BTC::findBitcoinValue( const char *path ) const
{
	std::cout << "Info: Bitcoin convertion from file : " << path << "\n";
	try
	{
		std::ifstream &BTCRequestFile = openFile( path );

		for (std::string line; std::getline(BTCRequestFile, line); ) 
		{
			try
			{
				if ( !checkLineFormat(line, '|') )
					throw BTC::InvalidDateFormatException();
				
				// find btc value
				size_t	date = convertDateToNumber(line.substr(0, 10));
				float	value = atof(line.substr(12).c_str());
				
				std::map<size_t, float>::const_iterator it = database.upper_bound(date);
				it--;
				std::cout << "| " << line.substr(0, 10) << " => " << value << " = " << it->second * value << "\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << "| > Error: " << e.what() << '\n';
			}
			
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "> Error: " << e.what() << '\n';
	}
}
// ---




// Exceptions :
const char *BTC::CannotOpenFileException::what() const throw()
{
	return "Cannot open file.";
}

const char *BTC::InvalidDateFormatException::what() const throw()
{
	return "Invalid date format.";
}

const char *BTC::NegativeNumberException::what() const throw()
{
	return "Negative number.";
}

const char *BTC::TooLargeNumberException::what() const throw()
{
	return "Too large number.";
}

const char *BTC::BadInputException::what() const throw()
{
	return "Bad inputs.";
}
// ---