/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:48:25 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/04 11:51:49 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main( int argc, char **argv )
{
	if ( argc == 1 )
	{
		std::cerr << "Error: No arguments.\n";
		std::cerr << "Hint: Correct program format : ./btc <FILE PATH> [DATABASE PATH 1] [DATABASE PATH 2] ...\n";
		std::cerr << "Hint: Correct file format : YYYY-MM-DD | value\n";
		return 1;
	}

	BTC data = BTC();

	if ( argc >= 3 )
	{
		std::cout << "Warning: You are using your own databases\n";
		std::cout << "Hint: Correct database format : YYYY-MM-DD,value\n";

		for ( int i = 2; i < argc; i++ )
		{
			data.addBitcoinDatabase( argv[i] );
		}
	}
	else
	{
		std::cout << "Info: Loading default data file\n";
		data.addBitcoinDatabase( "data.csv" );
	}

	data.findBitcoinValue( argv[1] );

	return 0;
}