/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 17:28:21 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	employee("Employee", 150);
	Form		form("alpha", 1, 1);

	std::cout << boss << std::endl;
	std::cout << employee << std::endl;
	std::cout << form << std::endl << std::endl;

	// Form exceptions
	try
	{
		Form	form("alpha", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form	form("alpha", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ---

	std::cout << std::endl;

	// Form actions
	try
	{
		employee.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form << std::endl << std::endl;

	boss.signForm(form);
	std::cout << form << std::endl;
	// ---

	
	return 0;
}