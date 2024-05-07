/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:38:33 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/07 14:10:24 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}


void	Harl::debug(){
	std::cout <<  "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	this->info();
}

void	Harl::info(){
	std::cout <<  "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	this->warning();
}

void	Harl::warning(){
	std::cout <<  "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	this->error();
}

void	Harl::error(){
	std::cout <<  "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

static int getLevel(std::string level){
    if (level == "DEBUG")
        return 0;
    if (level == "INFO")
        return 1;
    if (level == "WARNING")
        return 2;
    if (level == "ERROR")
        return 3;
    return -1;
}

void	Harl::complain( std::string level ){
	void (Harl::*MemberFunctionPtr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	switch (getLevel(level))
	{
	case 0:
		(this->*MemberFunctionPtr[0])();
		break;
	case 1:
		(this->*MemberFunctionPtr[1])();
		break;
	case 2:
		(this->*MemberFunctionPtr[2])();
		break;
	case 3:
		(this->*MemberFunctionPtr[3])();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}