/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:12:47 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 11:38:30 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string		name;
		AMateria*		materias[4];
	public:
		// Canonical Form :
		Character();
		Character( Character const & toCopy );
		Character & operator=( Character const & toCopy );
		~Character();
		
		// Specifics Constructors :
		Character( std::string const & name );
		
		// Utility Function :
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
		
		// Getters and Setters :
		std::string const & getName() const;
};