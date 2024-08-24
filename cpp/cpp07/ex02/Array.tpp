/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:22:50 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/25 15:25:21 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

// Canonical form
template <typename T>
Array<T>::Array() : elements(NULL), array_size(0)
{
}

template <typename T>
Array<T>::Array( const Array &toCopy ) : elements(NULL), array_size(0)
{
	*this = toCopy;
}

template <typename T>
Array<T> & Array<T>::operator=( const Array &toCopy )
{
	if (this != &toCopy)
	{
		if (this->elements)
			delete[] this->elements;
		this->array_size = toCopy.array_size;
		this->elements = new T[this->array_size];
		for (size_t i = 0; i < this->array_size; i++)
			this->elements[i] = toCopy.elements[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->elements)
		delete[] this->elements;
}
// ---



// Specifics Constructors
template <typename T>
Array<T>::Array( size_t size ) : elements(new T[size]), array_size(size)
{
}
// ---



// Specifics Operators
template <typename T>
T& Array<T>::operator[]( size_t index )
{
	if (index >= this->array_size)
		throw Array::IndexOutOfBoundException();
	return this->elements[index];
}
// ---



// Getters and Setters
template <typename T>
size_t	Array<T>::size( void ) const
{
	return this->array_size;
}
// ---



// Exceptions
template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw()
{
	return "Index out of bound";
}
// ---