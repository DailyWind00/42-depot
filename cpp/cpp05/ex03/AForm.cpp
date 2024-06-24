/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:40:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 09:54:23 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Canonical Form :
AForm::AForm() : 
		name("A form"), 
		isSigned(false),
		gradeToSign(150), 
		gradeToExecute(150)
{
}

AForm::AForm( AForm const & toCopy ) : 
		name(toCopy.name), 
		isSigned(toCopy.isSigned),
		gradeToSign(toCopy.gradeToSign), 
		gradeToExecute(toCopy.gradeToExecute)
{
}

AForm & AForm::operator=( AForm const & toCopy )
{
	if (this != &toCopy)
		isSigned = toCopy.isSigned;
	return *this;
}

AForm::~AForm()
{
}
// ---



// Specifics Constructors :
AForm::AForm( std::string const &name, int gradeToSign, int gradeToExecute ) : 
		name(name), 
		isSigned(false),
		gradeToSign(gradeToSign), 
		gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}
// ---



// Utility Function :
void	AForm::beSigned( Bureaucrat const &bureaucrat )
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	isSigned = true;
}
// ---



// Getters and Setters :
std::string const & AForm::getName() const
{
	return name;
}

bool	AForm::getIsSigned() const
{
	return isSigned;
}

int	AForm::getGradeToSign() const
{
	return gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return gradeToExecute;
}
// ---



// Exceptions :
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
// ---



std::ostream & operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.getName() << " is ";
	if (form.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and need grade " << form.getGradeToSign() << " to be signed and grade " << form.getGradeToExecute() << " to be executed";
	return os;
}