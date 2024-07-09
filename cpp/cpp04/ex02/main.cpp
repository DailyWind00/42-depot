/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:00 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 10:22:31 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "Modify the main to check if you can cast to the new abstract class Animal\n\n";
	
	// Should not compile :
	// Animal Error = Animal();

	// Should compile :
	Animal *animal = new Dog();
	animal->makeSound();
	delete animal;

	animal = new Cat();
	animal->makeSound();
	delete animal;

	return 0;
}