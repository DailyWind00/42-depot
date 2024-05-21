/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:25:50 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 10:31:48 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public :
		// Canonical Form :
		FragTrap();
		FragTrap( const FragTrap &fragtrap );
		FragTrap & operator=( const FragTrap &fragtrap );
		~FragTrap();
		
		// Specifics Constructors :
		FragTrap( std::string name );
	
		// Utility Function :
		void	highFivesGuys( void );
};