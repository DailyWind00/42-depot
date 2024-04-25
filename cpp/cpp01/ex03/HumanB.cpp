/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:37:54 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 23:37:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

std::string	HumanB::getName() { return this->name; }
Weapon*		HumanB::getWeapon() { return this->weapon; }
void	HumanB::setName(std::string name) { this->name = name; }
void	HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

void	HumanB::attack()
{
	if (this->weapon == NULL || this->weapon->getType() == "")
		std::cout << this->name << " attacks with his bare hands" << std::endl;
	else
		std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
