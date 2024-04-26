/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:20:49 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 16:54:38 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main ( void )
{
	Animal* j = new Cat();
	const Animal* i = new Dog();

	j->makeSound(); //will not output the cat sound!
	i->makeSound();//will output the dog sound!
	delete j;//should not create a leak
	delete i;


	const Animal* meta = new Animal();
	const Animal* jay = new Dog();
	const Animal* ii = new Cat();
	std::cout << jay->getType() << " " << std::endl;
	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound(); //will output the cat sound!
	jay->makeSound();
	meta->makeSound();




	return 0;
}