/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:34 by mgallais          #+#    #+#             */
/*   Updated: 2024/08/07 10:42:40 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Canonical Form :
Bureaucrat::Bureaucrat() : 
		name("Intern"), 
		grade(150)
{
}

Bureaucrat::Bureaucrat( Bureaucrat const & toCopy ) : 
		name(toCopy.name), 
		grade(toCopy.grade)
{
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & toCopy )
{
	if (this != &toCopy)
	{
		grade = toCopy.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}
// ---



// Specifics Constructors :
Bureaucrat::Bureaucrat( std::string const & name, int grade ) : 
		name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat( std::string const & name ) : 
		name(name), 
		grade(150)
{
}

Bureaucrat::Bureaucrat( int grade ) : name("Intern")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}
// ---



// Specifics Operators :
Bureaucrat &Bureaucrat::operator++()
{
	incrementGrade();
	return *this;
}

Bureaucrat Bureaucrat::operator++( int )
{
	Bureaucrat tmp(*this);
	incrementGrade();
	return tmp;
}

Bureaucrat & Bureaucrat::operator--()
{
	decrementGrade();
	return *this;
}

Bureaucrat Bureaucrat::operator--( int )
{
	Bureaucrat tmp(*this);
	decrementGrade();
	return tmp;
}
// ---



// Utility Function :
void Bureaucrat::incrementGrade( int amount )
{
	if (grade - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade - amount > 150)
		throw Bureaucrat::GradeTooLowException();
	grade -= amount;
}

void Bureaucrat::decrementGrade( int amount )
{
	if (grade + amount < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	grade += amount;
}

void Bureaucrat::printGrade() const
{
	std::cout << name << " is grade " << grade << std::endl;
}

void Bureaucrat::signForm( AForm &form )
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << name << " can't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "executeForm : Failure : " << e.what() << '\n';
	}
	
}
// ---



// Getters and Setters :
std::string const & Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}
// ---



// Exceptions :
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
// ---



std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;
}