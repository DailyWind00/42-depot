/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:39 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 10:43:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {
	protected :
		std::string type;
	public :
		// Canonical Form :
		Animal();
		Animal( const Animal &animal );
		Animal & operator=( const Animal &animal );
		virtual ~Animal();

		// Utility Function :
		virtual void makeSound( void ) const;

		// Getters and Setters
		std::string	getType( void ) const;
};
