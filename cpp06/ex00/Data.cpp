/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:32:44 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 18:08:05 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int     getPrecision(const std::string& literal)
{
    size_t  decimalPos = literal.find('.');
    int             precision = 1;

    if (decimalPos != std::string::npos)
        precision = static_cast<int>(literal.length() - decimalPos -
            (literal.find('f') != std::string::npos ? 2 : 1));
    return precision;
}

int	get_type(std::string const &str)
{
	int i = 0;
	int type = 0;
	std::string strs = str;
	bool allSpaces = true;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it != ' ')
		{
			allSpaces = false;
			break ;
		}
	}
	if (str.empty() || allSpaces)
		return (0);
	for (std::string::iterator it = strs.begin(); it != strs.end(); ++it)
	{
		if (*it == ' ')
		{
			std::cerr << "Error: invalid string" << std::endl;
			exit(1);
		}
	}
	bool chars = false;
	for (std::string::iterator it = strs.begin(); it != strs.end(); ++it)
	{
		if (isalpha(*it))
		{
			if (chars)
			{
				std::cerr << "Error: invalid string" << std::endl;
				exit(1);
			}
			chars = true;
		}
	}
	
	if (!(str.find("-inff") || str.find("+inff") || str.find("nanf")
		|| str.find("inff") || str.find("-inf") || str.find("+inf")
		|| str.find("nan") || str.find("inf")))
		return (-1);
	if (str.find_first_not_of("0123456789.-+f") != std::string::npos)
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		type = 3;
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == 'f')
		type = 2;
	else if (str[i] == '\0' && type != 3)
		type = 4;
	return (type);
}

void	PseudoLiteral(std::string const &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "-inff" || str == "+inff" || str == "nanf"
		|| str == "inff" || str == "-inf" || str == "+inf")
		std::cout << "float: " << str << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (str == "-inf" || str == "+inf" || str == "nan")
		std::cout << "double: " << str << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	charLiteral(std::string const &str)
{
	char c = str[0];
	int i = static_cast<int>(c);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	floatLiteral(std::string const &str)
{
	float f = std::strtof(str.c_str(), NULL);
	std::cout << "char: ";
	if (f >= 32 && f <= 126)
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (f <= INT_MAX && f >= INT_MIN)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(getPrecision(str)) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(getPrecision(str)) << static_cast<double>(f) << std::endl;
}

void	doubleLiteral(std::string const &str)
{
	double d = std::strtod(str.c_str(), NULL);
	std::cout << "char: ";
	if (d >= 32 && d <= 126)
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (d <= INT_MAX && d >= INT_MIN)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: "<< std::fixed << std::setprecision(getPrecision(str)) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(getPrecision(str)) << d << std::endl;
}

void	intLiteral(std::string const &str)
{
	int i = std::atoi(str.c_str());
	std::cout << "char: ";
	if (i >= 32 && i <= 126)
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(getPrecision(str)) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(getPrecision(str)) << static_cast<double>(i) << std::endl;
}