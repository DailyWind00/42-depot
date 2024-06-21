/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:40:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 17:19:41 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Canonical Form :
Form::Form() : 
		name("A form"), 
		isSigned(false),
		gradeToSign(150), 
		gradeToExecute(150)
{
}

Form::Form( Form const & toCopy ) : 
		name(toCopy.name), 
		isSigned(toCopy.isSigned),
		gradeToSign(toCopy.gradeToSign), 
		gradeToExecute(toCopy.gradeToExecute)
{
}

Form & Form::operator=( Form const & toCopy )
{
	if (this != &toCopy)
		isSigned = toCopy.isSigned;
	return *this;
}

Form::~Form()
{
}
// ---



// Specifics Constructors :
Form::Form( std::string const &name, int gradeToSign, int gradeToExecute ) : 
		name(name), 
		isSigned(false),
		gradeToSign(gradeToSign), 
		gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}
// ---



// Utility Function :
void	Form::beSigned( Bureaucrat const &bureaucrat )
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}
// ---



// Getters and Setters :
std::string const & Form::getName() const
{
	return name;
}

bool	Form::getIsSigned() const
{
	return isSigned;
}

int	Form::getGradeToSign() const
{
	return gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return gradeToExecute;
}
// ---



// Exceptions :
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
// ---



std::ostream & operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << " is ";
	if (form.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and need grade " << form.getGradeToSign() << " to be signed and grade " << form.getGradeToExecute() << " to be executed";
	return os;
}