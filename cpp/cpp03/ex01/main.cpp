/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:38:18 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 10:00:51 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void    fight(ClapTrap *Alpha, ClapTrap *Beta)
{
    Alpha->attack(Beta->getName());
    Beta->takeDamage(Alpha->getAd());
}

int main() {
    ClapTrap    Bob = ClapTrap("Bob");
    ClapTrap    Rober = ClapTrap();
    ScavTrap    Michelle = ScavTrap("Michel");
    ScavTrap    Jacky = ScavTrap();

    // Constructors values :
    Bob.status();
    Rober.status();
    Michelle.status();
    Jacky.status();

    // Modify values for tests :
    Michelle.beRepaired(20);
    Jacky.takeDamage(5);

    Michelle.status();
    Jacky.status();

    Michelle.guardGate();
    Jacky.guardGate();

    // tests :
    fight(&Bob, &Rober);
    fight(&Rober, &Michelle);
    fight(&Michelle, &Jacky);
    fight(&Jacky, &Bob);
    
    
    Bob.status();
    Rober.status();
    Michelle.status();
    Jacky.status();

    // Death messages :
    Jacky.takeDamage(9999);
    Jacky.status();
    Jacky.attack(Bob.getName());
    Jacky.takeDamage(0);
    Jacky.beRepaired(0);
    Jacky.guardGate();

    return 0;
}
