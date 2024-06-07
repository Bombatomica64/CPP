/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:29:12 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 18:36:11 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    // Test case 1: Serialize a null pointer
    Data* ptr1 = NULL;
    uintptr_t raw1 = Serializer::serialize(ptr1);
    std::cout << "Serialized value of nullptr: " << raw1 << std::endl;
	Data *d1 = Serializer::deserialize(raw1);
	std::cout << "Deserialized value of nullptr: " << d1 << std::endl;
    // Test case 2: Serialize a valid pointer
    Data data;
    Data* ptr2 = &data;
	std::cout << "Address of valid pointer: " << ptr2 << std::endl;
    uintptr_t raw2 = Serializer::serialize(ptr2);
    std::cout << "Serialized value of valid pointer: " << raw2 << std::endl;
	Data *d2 = Serializer::deserialize(raw2);
	std::cout << "Deserialized value of valid pointer: " << d2 << std::endl;

    // Test case 3: Serialize a pointer to a dynamically allocated object
    Data* ptr3 = new Data;
	std::cout << "Address of dynamically allocated object: " << ptr3 << std::endl;
    uintptr_t raw3 = Serializer::serialize(ptr3);
    std::cout << "Serialized value of dynamically allocated object: " << raw3 << std::endl;
	Data *d3 = Serializer::deserialize(raw3);
	std::cout << "Deserialized value of dynamically allocated object: " << d3 << std::endl;

    // Clean up dynamically allocated memory
	// delete d1;
	// delete ptr1;
	// delete d2;
	// delete ptr2;
	// delete d3;
    // delete ptr3;

    return 0;
}