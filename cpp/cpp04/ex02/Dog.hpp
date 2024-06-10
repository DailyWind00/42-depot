/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:56 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 11:21:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private :
		Brain *brain;
	public :
		// Canonical Form :
		Dog();
		Dog( const Dog &dog );
		Dog & operator=( const Dog &dog );
		~Dog();

		// Utility Function :
		void makeSound( void ) const;
};
