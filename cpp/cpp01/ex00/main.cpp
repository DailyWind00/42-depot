/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:48:13 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 22:48:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	zombie = newZombie("Bob");
	Zombie*	zombie2 = newZombie("");
	zombie->announce();
	zombie2->announce();
	randomChump("Roberth");
	delete zombie;
	delete zombie2;
	return 0;
}