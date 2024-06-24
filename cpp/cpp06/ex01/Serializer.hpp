/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:38:02 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 16:18:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private :
		Serializer();
		Serializer( const Serializer &toCopy );
		Serializer & operator=( const Serializer &toCopy );
	public :
		/// Canonical Form :
		virtual ~Serializer() = 0;
		
		/// Utility Function :
		static uintptr_t	serialize( Data* ptr );
		static Data* 		deserialize( uintptr_t raw );
};