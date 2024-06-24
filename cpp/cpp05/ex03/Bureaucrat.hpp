/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:21 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
	private :
		std::string const	name;
		int		grade;

	public :
		/// Canonical Form :
		Bureaucrat();
		Bureaucrat( const Bureaucrat &toCopy );
		Bureaucrat & operator=( const Bureaucrat &toCopy );
		~Bureaucrat();
		
		/// Specifics Constructors :
		Bureaucrat( std::string const &name, int grade );
		Bureaucrat( std::string const &name );
		Bureaucrat( int grade );

		/// Specifics Operators :
		Bureaucrat & operator++();
		Bureaucrat operator++( int );
		Bureaucrat & operator--();
		Bureaucrat operator--( int );
		
		/// Utility Function :
		void	incrementGrade( int amount = 1 );
		void	decrementGrade( int amount = 1 );
		void	printGrade() const;
		void	signForm( class AForm &form );
		void	executeForm(AForm const & form);
		
		/// Getters and Setters :
		std::string const & getName() const;
		int		getGrade() const;

		/// Exceptions :
		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
std::ostream & operator<<(std::ostream &os, const Bureaucrat &bureaucrat);