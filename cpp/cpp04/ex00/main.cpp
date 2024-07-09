/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:00 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 09:58:33 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal* wrongCat = new WrongCat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	
	delete wrongCat;
	delete wrongAnimal;

	return 0;
}