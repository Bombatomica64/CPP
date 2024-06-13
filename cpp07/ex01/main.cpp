/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:10:27 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/13 15:41:00 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

int main()
{
    // Test case 1: Array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(int);
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    // Test case 2: Array of characters
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArraySize = sizeof(charArray) / sizeof(char);
    iter(charArray, charArraySize, printElement<char>);
    std::cout << std::endl;

    // Test case 3: Array of strings
    std::string stringArray[] = {"Hello", "World", "GitHub", "Copilot", "is", "dumb"};
    size_t stringArraySize = sizeof(stringArray) / sizeof(std::string);
    iter(stringArray, stringArraySize, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}