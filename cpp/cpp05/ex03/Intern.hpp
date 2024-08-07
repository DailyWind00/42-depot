/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:01:45 by mgallais          #+#    #+#             */
/*   Updated: 2024/08/07 10:44:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern {
	private :
		AForm * makeShrubberyCreationForm( std::string const &target );
		AForm * makeRobotomyRequestForm( std::string const &target );
		AForm * makePresidentialPardonForm( std::string const &target );
		
	public :
		/// Canonical Form :
		Intern();	
		Intern( const Intern &toCopy );
		Intern & operator=( const Intern &toCopy );
		~Intern();
	
		/// Utility Function :
		AForm * makeForm( std::string const &formName, std::string const &target );

		/// Exceptions :
		class UnknownFormException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};