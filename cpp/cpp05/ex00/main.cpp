/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 14:23:18 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	// GradeTooHighException :
	try
	{
		Bureaucrat intern("Intern", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ---

	// GradeTooLowException :
	try
	{
		Bureaucrat intern("Intern", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ---

	// Normal case :
	try
	{
		Bureaucrat intern("Intern", 42);

		// Increments :
		std::cout << "\nIncrements : \n";
		std::cout << intern << std::endl;
		intern.incrementGrade();
		intern.printGrade();
		intern.incrementGrade(10);
		intern.printGrade();
		++intern;
		intern.printGrade();
		intern++;
		std::cout << intern << std::endl;
		// ---

		// Decrements :
		std::cout << "\nDecrements : \n";
		std::cout << intern << std::endl;
		intern.decrementGrade();
		intern.printGrade();
		intern.decrementGrade(10);
		intern.printGrade();
		--intern;
		intern.printGrade();
		intern--;
		std::cout << intern << std::endl;
		// ---
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ---

	// Exceptions craches the program if not catched :
	// Bureaucrat intern("Intern", 0);
	
	return 0;
}