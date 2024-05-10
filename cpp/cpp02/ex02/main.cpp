/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:38:18 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/10 17:28:58 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define BRed "\033[1;31m" 
#define Color_Off "\033[0m"

int main( void )
{
	std::cout << BRed << "[NOTICE] See subject to compare results\n\n" << Color_Off;
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << BRed << "\nCustom tests :\n" << Color_Off;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	
	std::cout << "\nSimple tests :\n";
	std::cout << "a + 1 = " << a + 1 << std::endl;
	std::cout << "a - 1 = " << a - 1 << std::endl;
	std::cout << "a * 1 = " << a * 1 << std::endl;
	std::cout << "a / 1 = " << a / 1 << std::endl;
	std::cout << "b / 0 = " << a / 0 << std::endl; // invalid
	std::cout << std::endl;
	std::cout << "b + 1 = " << b + 1 << std::endl;
	std::cout << "b - 1 = " << b - 1 << std::endl;
	std::cout << "b * 1 = " << b * 1 << std::endl;
	std::cout << "b / 1 = " << b / 1 << std::endl;
	std::cout << "b / 0 = " << b / 0 << std::endl; // invalid
	std::cout << std::endl;
	std::cout << "a + 256 = " << a + 256 << std::endl;
	std::cout << "a - 256 = " << a - 256 << std::endl;
	std::cout << "a * 256 = " << a * 256 << std::endl;
	std::cout << "a / 256 = " << a / 256 << std::endl;
	std::cout << std::endl;
	std::cout << "b + 256 = " << b + 256 << std::endl;
	std::cout << "b - 256 = " << b - 256 << std::endl;
	std::cout << "b * 256 = " << b * 256 << std::endl;
	std::cout << "b / 256 = " << b / 256 << std::endl;
	std::cout << std::endl;
	
	std::cout << "\nHard tests :\n";
	std::cout << "a + b - a * b / a = " << a + b - a * b / a << std::endl;
	
	
	return 0;
}