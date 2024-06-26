/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:25:05 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/25 16:52:44 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
typename std::vector<T>::iterator easyfind( std::vector<T> &v, T value )
{
	typename std::vector<T>::iterator it = std::find(v.begin(), v.end(), value);
	if (it == v.end())
		throw std::exception();
	return it;
}