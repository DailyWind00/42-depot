/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:56:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/08/07 18:14:48 by mgallais         ###   ########.fr       */
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

	// Does not compile because the type of the array is not the same as the type of the function
	// iter(array2, 8, printInt);

	
	return 0;
}