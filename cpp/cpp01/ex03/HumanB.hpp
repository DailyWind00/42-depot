/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:28:57 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 23:28:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();

		/* Getters and Setters */
		std::string	getName();
		Weapon*		getWeapon();
		void	setName(std::string name);
		void	setWeapon(Weapon& weapon);
};

#endif