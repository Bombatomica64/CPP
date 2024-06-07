/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:38:20 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 17:05:37 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string const &str)
{
	int type = get_type(str);

	std::cout << "type: " << type << std::endl;
	switch (type)
	{
		case -1:
			PseudoLiteral(str);
			break ;
		case 0:
			std::cerr << "Error: empty string" << std::endl;
			break ;
		case 1:
			charLiteral(str);
			break ;
		case 2:
			floatLiteral(str);
			break ;
		case 3:
			doubleLiteral(str);
			break ;
		case 4:
			intLiteral(str);
			break ;
		default:
			std::cerr << "Error: invalid string" << std::endl;
			break ;
	}
}