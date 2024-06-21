/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:44:37 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 11:37:18 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Fire : public AMateria
{
	public:
		// Canonical Form :
		Fire();
		Fire(Fire const & toCopy);
		// Fire & operator=(Fire const & toCopy); // Not needed
		~Fire();
		
		// Utility Function :
		AMateria * clone() const;
		void use(ICharacter & target);
};;