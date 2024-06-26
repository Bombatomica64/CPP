/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:36:26 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 16:19:29 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ( int ac , char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	std::string str = av[1];
	ScalarConverter::convert(str);
}