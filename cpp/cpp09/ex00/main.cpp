/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:48:25 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/03 15:47:26 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main( int argc, char **argv )
{
	if ( argc != 2 && argc != 3 )
	{
		std::cerr << "Error: Invalid arguments.\n";
		std::cerr << "Hint: Correct program format : ./btc <FILE PATH> [DATABASE FILE PATH]\n";
		std::cerr << "Hint: Correct file format : YYYY-MM-DD | value\n";
		return 1;
	}

	const char *database = "./data.csv";
	if ( argc == 3 )
	{
		std::cout << "Warning: You are using your own database, keep in mind it MUST have no syntax errors !\n";
		std::cout << "Warning: There is no error parsing for the database as it is not ask in the subject, so expect undefined behavior if you don't respect the format !\n";
		std::cout << "Hint: Correct database format : YYYY-MM-DD,value\n";
		database = argv[2];
	}

	BTC data = BTC();
	
	data.addBitcoinDatabase( database );
	// data.findBitcoinValue( argv[1] );

	return 0;
}