/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:32:44 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 12:44:14 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	get_type(std::string const &str)
{
	int i = 0;
	int type = 0;
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
	if (str.find("-inff") || str.find("+inff") || str.find("nanf")
		|| str.find("inff") || str.find("-inf") || str.find("+inf")
		|| str.find("nan") || str.find("inf"))
		return (-1);
	if (str.find_first_not_of("0123456789.-+f") != std::string::npos)
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == 'f')
		type = 2;
	else if (str[i] == '\0')
		type = 3;
	return (type);
}