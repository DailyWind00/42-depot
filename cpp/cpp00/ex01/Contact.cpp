/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:00:46 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/25 15:29:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	isEmpty = true;
	FName = "";
	LName = "";
	NName = "";
	PhoneNumber = "";
	Secret = "";

}

Contact::~Contact(){}

std::string Contact::getFName(){return FName;}
std::string Contact::getLName(){return LName;}
std::string Contact::getNName(){return NName;}
std::string Contact::getPhoneNumber(){return PhoneNumber;}
std::string Contact::getSecret(){return Secret;}
bool 		Contact::getIsEmpty(){return isEmpty;}
void Contact::setFName(std::string fName){FName = fName;}
void Contact::setLName(std::string lName){LName = lName;}
void Contact::setNName(std::string nName){NName = nName;}
void Contact::setPhoneNumber(std::string phoneNumber){PhoneNumber = phoneNumber;}
void Contact::setSecret(std::string secret){Secret = secret;}
void Contact::setIsEmpty(bool empty){isEmpty = empty;}

/* ************************************************************************** */

void	Contact::addEntry()
{
	std::cout << ">>> First name: ";
	std::cin >> FName;
	std::cout << ">>> Last name: ";
	std::cin >> LName;
	std::cout << ">>> Nickname: ";
	std::cin >> NName;
	std::cout << ">>> Phone number: ";
	std::cin >> PhoneNumber;
	std::cout << ">>> Darkest secret: ";
	std::cin >> Secret;
	isEmpty = false;

}
