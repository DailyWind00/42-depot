/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:44 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 11:26:34 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Canonical Form :
PresidentialPardonForm::~PresidentialPardonForm()
{
}
// ---



// Specifics Constructors :
PresidentialPardonForm::PresidentialPardonForm( std::string const &target ) : 
	AForm("Presidential Pardon Form", 25, 5),
	target(target)
{
}
// ---



// Utility Function :
void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	if (!isSigned)
		throw PresidentialPardonForm::FormUnsignedException();

	if (executor.getGrade() > gradeToExecute)
		throw Bureaucrat::GradeTooLowException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
// ---



// Getters and Setters :
std::string const & PresidentialPardonForm::getTarget() const
{
	return target;
}
// ---



// Exceptions :
const char * PresidentialPardonForm::FormUnsignedException::what() const throw()
{
	return "The form has not been signed.";
}
// ---