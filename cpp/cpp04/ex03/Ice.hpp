/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:12:19 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 11:37:27 by mgallais         ###   ########.fr       */
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
		~Ice();

		// Utility Function :
		AMateria * clone() const;
		void use(ICharacter & target);
};;