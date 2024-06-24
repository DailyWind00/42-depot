/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:01:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 12:27:57 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm * Intern::makeShrubberyCreationForm( std::string const &target )
{
	std::cout << "Intern creates a shrubbery creation form" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm * Intern::makeRobotomyRequestForm( std::string const &target )
{
	std::cout << "Intern creates a robotomy request form" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm * Intern::makePresidentialPardonForm( std::string const &target )
{
	std::cout << "Intern creates a presidential pardon form" << std::endl;
	return new PresidentialPardonForm(target);
}

// Canonical Form :
Intern::Intern()
{
}

Intern::Intern( const Intern &toCopy )
{
	*this = toCopy;
}

Intern & Intern::operator=( const Intern &toCopy )
{
	if (this != &toCopy)
	{
	}
	return *this;
}

Intern::~Intern()
{
}
// ---



// Utility Function :
AForm * Intern::makeForm( std::string const &formName, std::string const &target )
{
	AForm	*(Intern::*formMaker[3])( std::string const & ) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	
	std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			return (this->*formMaker[i])(target);
	}
	throw Intern::UnknownFormException();
}
// ---



// Exceptions :
const char *Intern::UnknownFormException::what() const throw()
{
	return "Unknown form";
}