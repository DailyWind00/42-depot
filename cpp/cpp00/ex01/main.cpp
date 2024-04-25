/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:49 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/25 16:03:08 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	PB = PhoneBook();
	std::string	input = "";
	
	std::cout << "Welcome to the PhoneBook !" << std::endl;
	std::cout << "> You can ADD, SEARCH or EXIT" << std::endl;
    while(42) {
		std::cin >> input;

		if (input == "ADD")
			PB.add();
		else if (input == "SEARCH")
			PB.search();
		else if (input == "EXIT")
			break ;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}
