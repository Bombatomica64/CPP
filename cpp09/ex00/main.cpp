/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:43:47 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/15 16:11:59 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
		return 1;
	}
	if (std::string(av[1]) == "empty")
	{
		std::cerr << "Invalid file" << std::endl;
		return 1;
	}

	std::string fileNm = av[1];

	if (fileNm.find(".csv") == std::string::npos 
		&& fileNm.find(".txt") == std::string::npos)
	{
		std::cerr << "Invalid file" << std::endl;
		return 1;
	}
	
	
	BitcoinExchange exchange;
	exchange.readFromFile(av[1]);
	exchange.display();
	return 0;
}