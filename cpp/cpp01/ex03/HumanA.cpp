/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:31:25 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 23:31:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

std::string	HumanA::getName() { return this->name; }
void	HumanA::setName(std::string name) { this->name = name; }

void	HumanA::attack()
{
	if (this->weapon.getType() == "")
		std::cout << this->name << " attacks with his bare hands" << std::endl;
	else
		std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
