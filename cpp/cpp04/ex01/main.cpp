/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:00 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 10:17:09 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	Animal* animals[10];
	for (int i = 0; i < 5; i++) {
		std::cout << std::endl;
		animals[i] = new Dog();
	}
	for (int i = 5; i < 10; i++) {
		std::cout << std::endl;
		animals[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		std::cout << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << std::endl;
	std::cout << "Deep copy proof :\n";
	std::cout << "  Should crash if not implemented correctly\n";
	Cat cat;
	Cat cat2(cat);
	Cat cat3 = cat;
	cat3.makeSound();
	cat2.makeSound();
	cat.makeSound();

	return 0;
}