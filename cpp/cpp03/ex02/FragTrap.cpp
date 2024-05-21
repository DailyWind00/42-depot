/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:25:30 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 10:44:42 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Canonical Form :
FragTrap::FragTrap()
{
	this->Name = "a true random guy";
	this->Hp = 100;
	this->Ep = 100;
	this->Ad = 30;
	this->Type = "FragTrap";
	this->Dead = false;
	std::cout << "[" << this->Type << "] " << this->Name << " joined the game\n";
}

FragTrap::FragTrap( const FragTrap &fragtrap )
{
	*this = fragtrap;
}

FragTrap & FragTrap::operator=( const FragTrap &fragtrap )
{
	this->Name = fragtrap.Name;
	this->Hp = fragtrap.Hp;
	this->Ep = fragtrap.Ep;
	this->Ad = fragtrap.Ad;
	this->Type = "FragTrap";
	this->Dead = false;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[" << this->Type << "] " << this->Name << " quit the game\n";
}
// ---



// Specifics Constructors :
FragTrap::FragTrap( std::string name )
{
	this->Name = name;
	this->Hp = 100;
	this->Ep = 100;
	this->Ad = 30;
	this->Type = "FragTrap";
	this->Dead = false;
	std::cout << "[" << this->Type << "] " << this->Name << " joined the game\n";
}
// ---



// Utility Function :
void	FragTrap::highFivesGuys( void )
{
	if (this->Dead)
	{
		std::cout << "[" << this->Type << "] " << this->Name << " is dead and cannot request a high fives !\n";
		return ;
	}
	std::cout << "[" << this->Type << "] " << this->Name << " is requesting a high fives\n";
}
// ---