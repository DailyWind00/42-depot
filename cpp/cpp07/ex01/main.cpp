/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:56:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/25 09:20:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void	printInt(int const & i)
{
	std::cout << i << " ";
}

void	printChar(char const & c)
{
	std::cout << c << " ";
}

int main( void ) {
	
	int		array[] = {1, 2, 3, 4, 5};
	char	array2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	iter(array, 5, printInt);
	std::cout << std::endl;

	iter(array2, 8, printChar);
	std::cout << std::endl;
	
	return 0;
}