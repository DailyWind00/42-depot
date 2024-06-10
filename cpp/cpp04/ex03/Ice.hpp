/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:12:19 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/10 11:50:29 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Canonical Form :
		Ice();
		Ice(Ice const & toCopy);
		// Ice & operator=(Ice const & toCopy); // Not needed
		virtual ~Ice();

		// Utility Function :
		AMateria * clone() const;
		void use(ICharacter & target);
};;