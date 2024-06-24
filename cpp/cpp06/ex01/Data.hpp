/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:44:47 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 15:51:20 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data {
	private:
		int value;

	public:
		// Canonical Form
		Data();
		Data(const Data& toCopy);
		Data& operator=(const Data& toCopy);
		virtual ~Data();

		// Specifics Constructors :
		Data( int val );

		// getters and setters
		void setValue( int newValue );
		int getValue() const;
};
