/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:53:02 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/05 10:54:02 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	
	if ( argc != 2 )
	{
		std::cerr << "Error: Invalid arguments\n";
		std::cerr << "Info: Correct syntax : ./RPN \"calculation\"\n";
		return 1;
	}

	RPNCalculator calculator;
	
	size_t	result = calculator.calculate( (std::string)argv[1] );

	if ( result == (size_t)-1 )
	{
		std::cerr << "Error: Failed to calculate\n";
		return 1;
	}

	std::cout << "> " << result << "\n";

	return 0;
}