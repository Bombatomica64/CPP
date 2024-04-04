/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:32:41 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/04 12:18:23 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FILEPATH: /nfs/homes/lmicheli/Documents/CPP/cpp01/ex00/test_Zombie.hpp

#include <cassert>
#include <iostream>
#include <sstream>
#include "Zombie.hpp"

void test_constructor() {
	Zombie zombie("Test Zombie");
	assert(zombie.getName() == "Test Zombie");
	std::cout << "Constructor test passed.\n";
}

void test_copy_constructor() {
	Zombie zombie1("Original Zombie");
	Zombie zombie2 = zombie1;
	assert(zombie2.getName() == "Original Zombie");
	std::cout << "Copy constructor test passed.\n";
}

void test_setName() {
	Zombie zombie("Old Name");
	zombie.setName("New Name");
	assert(zombie.getName() == "New Name");
	std::cout << "setName test passed.\n";
}

void test_announce() {
	Zombie zombie("Announcer");
	// Assuming announce() prints "<name> says Braiiiiiiinnnssss..."
	// You need to capture the output and compare it with the expected output
	// std::stringstream buffer;
	// std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	zombie.announce();
	// std::string text = buffer.str();
	// std::cout.rdbuf(old);
	// assert(text == "Announcer says Braiiiiiiinnnssss...\n");
	// std::cout << "announce test passed.\n";
}

int main() {
	test_constructor();
	test_copy_constructor();
	test_setName();
	test_announce();
	return 0;
}