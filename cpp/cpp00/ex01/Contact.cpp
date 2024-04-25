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
