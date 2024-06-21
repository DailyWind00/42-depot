/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:52:26 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 11:32:33 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#define RED "\033[31m"
#define AQUA "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"


class AMateria
{
	protected:
		const std::string	type;
	public:
		// Canonical Form :
		AMateria();
		AMateria( const AMateria &toCopy );
		// AMateria & operator=( const AMateria &toCopy ); // Not needed here
		virtual ~AMateria();

		// Specifics Constructors :
		AMateria( std::string const & type );
		
		// Utility Function :
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		
		// Getters and Setters :
		std::string const & getType() const;
};
