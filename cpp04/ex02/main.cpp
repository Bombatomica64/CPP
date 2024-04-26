/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:20:49 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 18:33:50 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main ( void )
{
	// Animal* meta = new Animal();
	std::cout << "-------------------" << std::endl;
	Animal* j = new Cat();
	const Animal* i = new Dog();

	j->makeSound(); //will not output the cat sound!
	i->makeSound();//will output the dog sound!
	delete j;//should not create a leak
	delete i;


	// const Animal* meta = new Animal();
	const Animal* jay = new Dog();
	const Animal* ii = new Cat();
	std::cout << jay->getType() << " " << std::endl;
	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound(); //will output the cat sound!
	jay->makeSound();
	// meta->makeSound();

	// delete meta;
	delete jay;
	delete ii;

	WrongCat* wcat = new WrongCat();
	wcat->makeSound();

	delete wcat;

	std::cout << "-------------------" << std::endl;

	Animal *animals[6];

	for (int i = 0; i < 3; i++) {
		animals[i] = new Dog();	}

	for (int i = 3; i < 6; i++) {
		animals[i] = new Cat();  }

	for (int i = 0; i < 6; i++) {
		delete animals[i];       }

	std::cout << "-------------------" << std::endl;

	return 0;
}