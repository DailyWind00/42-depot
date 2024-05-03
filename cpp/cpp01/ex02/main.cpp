/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:06:06 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 23:06:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* strPtr = &str;
	std::string& strRef = str;

	std::cout << "> Adresses : " << std::endl;
	std::cout << "Pointer: " << strPtr << " (value stocked in the ptr)" << std::endl;
	std::cout << "Reference: " << &strRef << std::endl;

	std::cout << "> Values : " << std::endl;
	std::cout << "Pointer: " << *strPtr << std::endl;
	std::cout << "Reference: " << strRef << std::endl;

	return 0;
}
