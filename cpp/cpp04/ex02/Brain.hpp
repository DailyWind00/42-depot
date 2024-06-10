/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:49 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 11:18:49 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {
	private :
		std::string ideas[100];

	public :
		// Canonical Form :
		Brain();
		Brain( const Brain &brain );
		Brain & operator=( const Brain &brain );
		~Brain();
};
