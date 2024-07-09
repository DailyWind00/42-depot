/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:24 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 10:00:20 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Canonical Form :
Brain::Brain()
{
	std::cout << "[Brain] Default Constructor called called\n";
}

Brain::Brain( const Brain &brain )
{
	std::cout << "[Brain] Copy Constructor called\n";
	// Perform deep copy of ideas array
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain & Brain::operator=( const Brain &brain )
{
	std::cout << "[Brain] Copy assignment operator called\n";
	if (this != &brain) {
		// Perform deep copy of ideas array
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor called\n";
}
// ---