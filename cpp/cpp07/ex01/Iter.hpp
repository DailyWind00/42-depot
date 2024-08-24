/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:14:06 by mgallais          #+#    #+#             */
/*   Updated: 2024/08/24 10:57:33 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	iter(T * array, size_t size, void (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

// Because "We ShOuLd HaNdLe NoN-cOnSt..." 
template <typename T>
void	iter(T * array, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

