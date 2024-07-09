/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:39 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 09:56:08 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
	protected :
		std::string type;
	public :
		// Canonical Form :
		WrongAnimal();
		WrongAnimal( const WrongAnimal &wrongAnimal );
		WrongAnimal & operator=( const WrongAnimal &wrongAnimal );
		virtual ~WrongAnimal();

		// Utility Function :
		void makeSound( void ) const;

		// Getters and Setters
		std::string	getType( void ) const;
};
