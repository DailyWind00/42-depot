/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:04:22 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 10:07:14 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Canonical Form :
ClapTrap::ClapTrap()
{
	this->Name = "a random guy";
	this->Hp = 10;
	this->Ep = 10;
	this->Ad = 0;
	this->Type = "ClapTrap";
	this->Dead = false;
	std::cout << "[" << this->Type << "] " << this->Name << " joined the game\n";
}

ClapTrap::ClapTrap( const ClapTrap &claptrap )
{
	*this = claptrap;
}

ClapTrap & ClapTrap::operator=( const ClapTrap &claptrap )
{
	this->Name = claptrap.Name;
	this->Hp = claptrap.Hp;
	this->Ep = claptrap.Ep;
	this->Ad = claptrap.Ad;
	this->Type = "ClapTrap";
	this->Dead = false;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] " << this->Name << " quit the game\n";
}
// ---



// Specifics Constructors :
ClapTrap::ClapTrap( std::string name )
{
	this->Name = name;
	this->Hp = 10;
	this->Ep = 10;
	this->Ad = 0;
	this->Type = "ClapTrap";
	this->Dead = false;
	std::cout << "[" << this->Type << "] " << this->Name << " joined the game\n";
}
// ---



// Utility Function :
void ClapTrap::attack( const std::string& target )
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
	std::cout << "[" << this->Type << "] " << this->Name << " attacks " << target << ", causing " << this->Ad << " points of damage\n";
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if (this->Dead)
	{
		std::cout << "[" << this->Type << "] " << this->Name << " is already dead and cannot take damage no more !\n";
		return ;
	}
	std::cout << "[" << this->Type << "] " << this->Name << " took " << amount << " points of damage\n";
	while (amount--)
	{
		this->Hp--;
		if (this->Hp == 0)
		{
			this->Dead = true;
			std::cout << "[" << this->Type << "] " << this->Name << " died !\n";
			return ;
		}
	}
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if (this->Dead)
	{
		std::cout << "[" << this->Type << "] " << this->Name << " is already dead and cannot repair himself no more !\n";
		return ;
	}
	if (this->Ep == 0)
	{
		std::cout << "[" << this->Type << "] " << this->Name << " is too tired to repair himself !\n";
		return ;
	}
	this->Ep--;
	this->Hp += amount;
	std::cout << "[" << this->Type << "] " << this->Name << " healed himself for " << amount << " health point\n";
}

void ClapTrap::status( void )
{
	std::cout << "== " << this->Name << " status :\n";
	std::cout << "|| Type = " << this->Type << std::endl;
	std::cout << "|| Hp = " << this->Hp << std::endl;
	std::cout << "|| Ep = " << this->Ep << std::endl;
	std::cout << "|| Ad = " << this->Ad << std::endl;
	std::cout << "|| Dead = " << this->Dead << std::endl;
	std::cout << "== ---\n";
}
// ---



// Getters and Setters :
std::string ClapTrap::getName( void )
{
	return (this->Name);
}

int ClapTrap::getAd( void )
{
	return (this->Ad);
}

void ClapTrap::setAd( unsigned int amount )
{
	this->Ad = amount;
}
// ---