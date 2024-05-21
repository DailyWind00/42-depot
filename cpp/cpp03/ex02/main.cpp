/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:38:18 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 10:47:27 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    FragTrap    Brenda = FragTrap("Brenda");
    FragTrap    Kevin = FragTrap();

    // Constructors values :
    Bob.status();
    Rober.status();
    Michelle.status();
    Jacky.status();
    Brenda.status();
    Kevin.status();

    // Modify values for tests :
    Brenda.beRepaired(20);
    Kevin.takeDamage(5);

    Brenda.status();
    Kevin.status();

    Michelle.guardGate();
    Jacky.guardGate();
    Brenda.highFivesGuys();
    Kevin.highFivesGuys();

    // tests :
    fight(&Bob, &Rober);
    fight(&Rober, &Michelle);
    fight(&Michelle, &Jacky);
    fight(&Jacky, &Bob);
    fight(&Brenda, &Kevin);
    
    
    Bob.status();
    Rober.status();
    Michelle.status();
    Jacky.status();
    Brenda.status();
    Kevin.status();

    // Death messages :
    Brenda.takeDamage(9999);
    Brenda.status();
    Brenda.attack(Bob.getName());
    Brenda.takeDamage(0);
    Brenda.beRepaired(0);
    Brenda.highFivesGuys();

    return 0;
}
