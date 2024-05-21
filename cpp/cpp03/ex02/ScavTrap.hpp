/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:08:17 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 09:26:24 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public :
		// Canonical Form :
		ScavTrap();
		ScavTrap( const ScavTrap &scavtrap );
		ScavTrap & operator=( const ScavTrap &scavtrap );
		~ScavTrap();
		
		// Specifics Constructors :
		ScavTrap( std::string name );
	
		// Utility Function :
		void	attack( const std::string& target );
		void	guardGate( void );
};
