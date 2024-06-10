/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:50:10 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 11:04:42 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :
		// Canonical Form :
		WrongCat();
		WrongCat( const WrongCat &wrongCat );
		WrongCat & operator=( const WrongCat &wrongCat );
		~WrongCat();

		// Utility Function :
		void makeSound( void ) const;
};
