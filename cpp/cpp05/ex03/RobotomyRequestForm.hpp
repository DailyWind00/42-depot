/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:20 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 11:24:51 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string const	target;

	public :
		/// Canonical Form :
		// RobotomyRequestForm();
		// RobotomyRequestForm( const RobotomyRequestForm &toCopy );
		// RobotomyRequestForm & operator=( const RobotomyRequestForm &toCopy );
		virtual ~RobotomyRequestForm();
		
		/// Specifics Constructors :
		RobotomyRequestForm( std::string const &target );
		
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
