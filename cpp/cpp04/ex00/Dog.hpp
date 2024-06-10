/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:56 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 10:48:04 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	public :
		// Canonical Form :
		Dog();
		Dog( const Dog &dog );
		Dog & operator=( const Dog &dog );
		~Dog();

		// Utility Function :
		void makeSound( void ) const;
};
