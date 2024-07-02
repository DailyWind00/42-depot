/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:23:16 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/02 12:34:56 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Canonical Form :
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack &toCopy ) : std::stack<T>(toCopy)
{
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=( const MutantStack &toCopy )
{
	if (this == &toCopy)
		return *this;
	std::stack<T>::operator=(toCopy);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}
// ---



// Utility Function :
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}
// ---