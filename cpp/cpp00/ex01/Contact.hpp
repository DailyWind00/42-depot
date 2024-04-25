/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:50:28 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/25 15:24:38 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private :
		bool			isEmpty;
		std::string		FName;
		std::string		LName;
		std::string		NName;
		std::string		PhoneNumber;
		std::string		Secret;

	public :
		Contact();
		~Contact();

};

#endif