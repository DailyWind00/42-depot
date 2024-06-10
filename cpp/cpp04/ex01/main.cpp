/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:00 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 11:36:26 by mgallais         ###   ########.fr       */
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

	return 0;
}