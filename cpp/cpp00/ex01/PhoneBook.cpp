/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/26 09:11:14 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contactNumber = 0;
	oldestContact = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::add()
{
	if (this->contactNumber == this->oldestContact && !this->contacts[0].getIsEmpty())
		this->oldestContact = (this->oldestContact + 1) % 8;
	this->contacts[this->contactNumber].addEntry();
	this->contactNumber = (this->contactNumber + 1) % 8;
}

static void	printField(std::string field)
{
	if (field.length() > 10)
		std::cout << field.substr(0, 9) << ".";
	else
	{
		for (int i = 0; i < 10 - (int)field.length(); i++)
			std::cout << " ";
		std::cout << field;
	}
}

void PhoneBook::search()
{
	std::cout << "==========================================" << std::endl;
	std::cout << "Id| First Name |  Last Name |  Nickname  |" << std::endl;
	for (int i = 1; i <= 8; i++)
	{
		std::cout << i << " | ";
		if (this->contacts[i - 1].getIsEmpty())
			std::cout << "           |            |            |";
		else
		{
			printField(this->contacts[i - 1].getFName());
			std::cout << " | ";
			printField(this->contacts[i - 1].getLName());
			std::cout << " | ";
			printField(this->contacts[i - 1].getNName());
			std::cout << " | ";
		}
		if (i - 1 == this->oldestContact && !this->contacts[i - 1].getIsEmpty())
			std::cout << "<-- Oldest";
		std::cout << std::endl;
	}
	std::cout << "==========================================" << std::endl;
	std::cout << "Which contact do you want to see ?" << std::endl << ">>> Id: ";

	int id;
	std::cin >> id;
	if (id > 0 && id <= 8 && !this->contacts[id - 1].getIsEmpty())
	{
		std::cout << "First name: " << this->contacts[id - 1].getFName() << std::endl;
		std::cout << "Last name: " << this->contacts[id - 1].getLName() << std::endl;
		std::cout << "Nickname: " << this->contacts[id - 1].getNName() << std::endl;
		std::cout << "Phone number: " << this->contacts[id - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->contacts[id - 1].getSecret() << std::endl;
	}
	else
		std::cout << "!! This contact does not exist..." << std::endl;
	std::cout << "==========================================" << std::endl;
}
