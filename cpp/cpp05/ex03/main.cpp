/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 11:31:59 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	secretary("Secretary", 40);
	Bureaucrat	intern("Intern", 135);
	
	std::cout << boss << std::endl;
	std::cout << secretary << std::endl;
	std::cout << intern << std::endl;
	std::cout << std::endl;

	PresidentialPardonForm	*presidentialPardonForm = new PresidentialPardonForm("Rober");
	RobotomyRequestForm	*robotomyRequestForm = new RobotomyRequestForm("Bernard");
	ShrubberyCreationForm	*shrubberyCreationForm = new ShrubberyCreationForm("file");
	
	boss.executeForm(*presidentialPardonForm);
	boss.executeForm(*robotomyRequestForm);
	boss.executeForm(*shrubberyCreationForm);
	std::cout << std::endl;

	intern.signForm(*presidentialPardonForm);
	intern.signForm(*robotomyRequestForm);
	intern.signForm(*shrubberyCreationForm);
	std::cout << std::endl;

	secretary.signForm(*presidentialPardonForm);
	secretary.signForm(*robotomyRequestForm);
	secretary.signForm(*shrubberyCreationForm);
	std::cout << std::endl;

	boss.signForm(*presidentialPardonForm);
	boss.signForm(*robotomyRequestForm);
	boss.signForm(*shrubberyCreationForm);
	std::cout << std::endl;

	intern.executeForm(*presidentialPardonForm);
	intern.executeForm(*robotomyRequestForm);
	intern.executeForm(*shrubberyCreationForm);
	std::cout << std::endl;

	boss.executeForm(*presidentialPardonForm);
	boss.executeForm(*robotomyRequestForm);
	boss.executeForm(*shrubberyCreationForm);

	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete shrubberyCreationForm;

	return 0;
}