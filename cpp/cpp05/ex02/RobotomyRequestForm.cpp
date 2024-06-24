/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:28 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 11:26:08 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Canonical Form :
RobotomyRequestForm::~RobotomyRequestForm()
{
}
// ---



// Specifics Constructors :
RobotomyRequestForm::RobotomyRequestForm( std::string const &target ) : 
		AForm("Robotomy Request Form", 72, 45),
		target(target)
{
}
// ---



// Utility Function :
void	RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
	if (!isSigned)
		throw RobotomyRequestForm::FormUnsignedException();
	if (executor.getGrade() > gradeToExecute)
		throw Bureaucrat::GradeTooLowException();

	std::cout << "bzzzzzzzz\n";
	srand (time(NULL));
	int i = rand() % 2;
	if (i)
		std::cout << target << " has been robotomized !\n";
	else
		std::cout << target << " failed to be robotomized !\n";
}
// ---



// Getters and Setters :
std::string const & RobotomyRequestForm::getTarget() const
{
	return target;
}
// ---



// Exceptions :
const char * RobotomyRequestForm::FormUnsignedException::what() const throw()
{
	return "The form has not been signed.";
}
// ---