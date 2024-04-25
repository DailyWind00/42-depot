/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:55:34 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/25 16:03:38 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private :
		int		contactNumber;
		int		oldestContact;
		Contact	contacts[8];
	public :
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();

};

#endif