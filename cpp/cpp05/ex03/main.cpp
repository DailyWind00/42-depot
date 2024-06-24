/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 12:29:16 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern	intern;

	AForm	*presidentialPardonForm = intern.makeForm("presidential pardon", "Rober");
	AForm	*robotomyRequestForm = intern.makeForm("robotomy request", "Bernard");
	AForm	*shrubberyCreationForm = intern.makeForm("shrubbery creation", "file");
	std::cout << std::endl;
	
	Bureaucrat	boss("Boss", 1);

	std::cout << boss << std::endl;

	boss.executeForm(*presidentialPardonForm);
	boss.executeForm(*robotomyRequestForm);
	boss.executeForm(*shrubberyCreationForm);
	std::cout << std::endl;

	boss.signForm(*presidentialPardonForm);
	boss.signForm(*robotomyRequestForm);
	boss.signForm(*shrubberyCreationForm);
	std::cout << std::endl;

	boss.executeForm(*presidentialPardonForm);
	boss.executeForm(*robotomyRequestForm);
	boss.executeForm(*shrubberyCreationForm);
	
	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete shrubberyCreationForm;

	return 0;
}