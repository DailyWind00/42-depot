/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:56:55 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/25 09:07:28 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T & x, T & y)
{
    T buf = x;
    x = y;
    y = buf;
}

template <typename T>
T min(T const & x, T const & y)
{
	return x < y ? x : y;
}

template <typename T>
T max(T const & x, T const & y)
{
	return x > y ? x : y;
}