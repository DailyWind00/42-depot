/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:38:18 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/16 11:58:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void    fight(ClapTrap *Alpha, ClapTrap *Beta)
{
    Alpha->attack(Beta->getName());
    Beta->takeDamage(Alpha->getAd());
}

int main() {
    ClapTrap    Bob = ClapTrap("Bob");
    ClapTrap    Rober = ClapTrap();

    // Constructors values :
    Bob.status();
    Rober.status();

    // Modify values for tests :
    Bob.setAd(1);
    Rober.beRepaired(2);
    
    Bob.status();
    Rober.status();

    // tests :
    for (int i = 0; i < 10; i++)
    {
        fight(&Bob, &Rober);
    }
    
    Bob.status();
    Rober.status();

    // Death messages :
    Rober.takeDamage(2);
    Rober.status();
    Rober.attack(Bob.getName());
    Rober.takeDamage(0);
    Rober.beRepaired(0);

    return 0;
}
