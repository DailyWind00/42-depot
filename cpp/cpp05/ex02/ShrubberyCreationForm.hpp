/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:17:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 11:25:06 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string const	target;

	public :
		/// Canonical Form :
		// ShrubberyCreationForm();
		// ShrubberyCreationForm( const ShrubberyCreationForm &toCopy );
		// ShrubberyCreationForm & operator=( const ShrubberyCreationForm &toCopy );
		virtual ~ShrubberyCreationForm();
		
		/// Specifics Constructors :
		ShrubberyCreationForm( std::string const &target );
		
		/// Utility Function :
		void	execute( const Bureaucrat &executor ) const;
		
		/// Getters and Setters :
		std::string const & getTarget() const;

		/// Exceptions :
		class FileNotOpenException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class FormUnsignedException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
