/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:39:03 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 23:39:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

// HumanA = Reference to Weapon
// HumanB = Pointer to Weapon (because it can be NULL)
int	main()
{
	Weapon		weapon("crude spiked club");
	HumanA		humanA("Bob", weapon);
	HumanB		humanB("Jim");

	// HumanA attacks with crude spiked club
	// HumanB attacks with his NULL (bare hands)
	humanA.attack();
	humanB.attack();

	// HumanB equips weapon ()
	humanB.setWeapon(weapon);
	humanB.attack();

	// HumanA doesn't need to set weapon because it's a reference
	// HumanB need to set weapon because it's a pointer
	weapon.setType("rusty sword");
	humanA.attack();
	humanB.setWeapon(weapon);
	humanB.attack();

	// If Weapon type is empty or NULL, HumanA and HumanB will attack with bare hands
	weapon.setType("");
	humanA.attack();
	humanB.setWeapon(weapon);
	humanB.attack();
	return 0;
}
