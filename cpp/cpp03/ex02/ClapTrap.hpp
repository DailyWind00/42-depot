/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:58:07 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 09:32:09 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	protected :
		std::string 	Name;
		unsigned int	Hp;
		unsigned int	Ep;
		unsigned int	Ad;
		std::string		Type;
		bool			Dead;
	public :
		// Canonical Form :
		ClapTrap();
		ClapTrap( const ClapTrap &claptrap );
		ClapTrap & operator=( const ClapTrap &claptrap );
		~ClapTrap();
		
		// Specifics Constructors :
		ClapTrap( std::string name );
		
		// Utility Function :
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		void status( void );

		// Getters and Setters :
		std::string getName( void );
		int			getAd( void );
		void	setAd( unsigned int amount );
};

#endif