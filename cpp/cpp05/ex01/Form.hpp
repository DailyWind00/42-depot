/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:40:16 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 15:08:23 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private :
		const std::string	name;
		bool		isSigned;
		const int	gradeToSign;
		const int	gradeToExecute;

	public :
		// Canonical Form :
		Form();
		Form( const Form &toCopy );
		Form & operator=( const Form &toCopy );
		~Form();
		
		// Specifics Constructors :
		Form( std::string const &name, int gradeToSign, int gradeToExecute );
		
		// Utility Function :
		void	beSigned( const Bureaucrat &bureaucrat );

		// Getters and Setters :
		std::string const & getName() const;
		bool	getIsSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		// Exceptions :
		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

};
std::ostream & operator<<(std::ostream &os, const Form &form);