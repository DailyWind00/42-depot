/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:35 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 11:24:05 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string const	target;

	public :
		/// Canonical Form :
		// PresidentialPardonForm();
		// PresidentialPardonForm( const PresidentialPardonForm &toCopy );
		// PresidentialPardonForm & operator=( const PresidentialPardonForm &toCopy );
		virtual ~PresidentialPardonForm();
		
		/// Specifics Constructors :
		PresidentialPardonForm( std::string const &target );
		
		/// Utility Function :
		void	execute( const Bureaucrat &executor ) const;
		
		/// Getters and Setters :
		std::string const & getTarget() const;

		/// Exceptions :
		class FormUnsignedException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
