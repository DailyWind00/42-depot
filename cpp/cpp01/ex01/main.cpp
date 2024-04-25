/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:59:53 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 22:59:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	zombies = zombieHorde(5, "Bob");
	for (int i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	zombies = zombieHorde(3, "Roberth");
	for (int i = 0; i < 3; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}