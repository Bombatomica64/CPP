/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:20:49 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/07 11:32:37 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <unistd.h>
#include "WrongCat.hpp"

int main ( void )
{
	Animal *animals[6];

	for (int i = 0; i < 3; i++) {
		animals[i] = new Dog();	}

	for (int i = 3; i < 6; i++) {
		animals[i] = new Cat();  }

	for (int i = 0; i < 6; i++) {
		delete animals[i];       }

	Dog Basic;

	std::cout << "Basic type: " << Basic.getType() << std::endl;
	{
		Dog tmp = Basic;
	}

	sleep(3);
	return 0;
}