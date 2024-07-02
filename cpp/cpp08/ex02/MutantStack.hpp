/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:18:46 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/02 16:46:53 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		/// Canonical Form :
		MutantStack();
		MutantStack( const MutantStack &toCopy );
		MutantStack & operator=( const MutantStack &toCopy );
		~MutantStack();

		/// Utility Function :
		iterator begin();
		iterator end();
};
