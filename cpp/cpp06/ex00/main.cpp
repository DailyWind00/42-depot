/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:41:42 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 15:35:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( void )
{
	ScalarConverter::convert("0");
	ScalarConverter::convert("42.0");
	ScalarConverter::convert("42.42");
	ScalarConverter::convert("test");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");	
	
	return 0;
}
