/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:26:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 14:29:28 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ScalarConverter {
	public :
		/// Canonical Form : 
		ScalarConverter();
		ScalarConverter( const ScalarConverter &toCopy );
		ScalarConverter & operator=( const ScalarConverter &toCopy );
		virtual ~ScalarConverter() = 0;
		
		/// Utility Function :
		static void	convert( const std::string &toConvert );
		char	*charConvertion( const std::string &toConvert );
		char	*intConvertion( const std::string &toConvert );
		char	*floatConvertion( const std::string &toConvert );
		char	*doubleConvertion( const std::string &toConvert );
};
