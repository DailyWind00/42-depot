/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:22:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/25 11:45:02 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <typeinfo>

template <typename T>
class Array {
	private :
		T		*elements;
		size_t	array_size;

	public :
		/// Canonical Form :
		Array();
		Array( const Array &toCopy );
		Array & operator=( const Array &toCopy );
		~Array();
		
		/// Specifics Constructors :
		Array( size_t size );

		/// Specifics Operators :
		T& operator[]( size_t index );

		/// Getters and Setters :
		size_t	size( void ) const;

		/// Exceptions :
		class IndexOutOfBoundException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
