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
	
    while(42) {
		std::cin >> input;
		if (input == "ADD")
			;
		else if (input == "SEARCH")
			;
		else if (input == "EXIT")
			break ;
	}
	return 0;
}