/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:22:05 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 23:22:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(const std::string& type);
		~Weapon();
	
		/* Getters and Setters */
		const std::string&	getType() const;
		void	setType(const std::string& type);
};


#endif