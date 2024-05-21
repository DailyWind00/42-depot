/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:40:27 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 10:39:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Canonical Form :
ScavTrap::ScavTrap()
{
	this->Name = "a very random guy";
	this->Hp = 100;
	this->Ep = 50;
	this->Ad = 20;
	this->Type = "ScavTrap";
	this->Dead = false;
	std::cout << "[" << this->Type << "] " << this->Name << " joined the game\n";
}

ScavTrap::ScavTrap( const ScavTrap &scavtrap )
{
	*this = scavtrap;
}

ScavTrap & ScavTrap::operator=( const ScavTrap &scavtrap )
{
	this->Name = scavtrap.Name;
	this->Hp = scavtrap.Hp;
	this->Ep = scavtrap.Ep;
	this->Ad = scavtrap.Ad;
	this->Type = "ScavTrap";
	this->Dead = false;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[" << this->Type << "] " << this->Name << " quit the game\n";
}
// ---



// Specifics Constructors :
ScavTrap::ScavTrap( std::string name )
{
	this->Name = name;
	this->Hp = 100;
	this->Ep = 50;
	this->Ad = 20;
	this->Type = "ScavTrap";
	this->Dead = false;
	std::cout << "[" << this->Type << "] " << this->Name << " joined the game\n";
}
// ---



// Utility Function :
void	ScavTrap::attack( const std::string& target )
{
	if (this->Dead)
	{
		std::cout << "[" << this->Type << "] " << this->Name << " is already dead and cannot attack no more !\n";
		return ;
	}
	if (this->Ep == 0)
	{
		std::cout << "[" << this->Type << "] " << this->Name << " is too tired to attack !\n";
		return ;
	}
	this->Ep--;
	std::cout << "[" << this->Type << "] " << this->Name << " assault " << target << ", dealing " << this->Ad << " points of damage\n";
}

void	ScavTrap::guardGate( void )
{
	if (this->Dead)
	{
		std::cout << "[" << this->Type << "] " << this->Name << " is dead and cannot guard the gate !\n";
		return ;
	}
	std::cout << "[" << this->Type << "] " << this->Name << " is now guarding the gate\n";
}
// ---