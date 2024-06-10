/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:50:10 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 10:48:00 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
	public :
		// Canonical Form :
		Cat();
		Cat( const Cat &cat );
		Cat & operator=( const Cat &cat );
		~Cat();

		// Utility Function :
		void makeSound( void ) const;
};
