/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:36:15 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/17 16:17:42 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main ( int ac, char **av )
{
	if (ac == 1)
	{
		std::cout << "Usage: ./pmerge [numbers]" << std::endl;
		return 1;
	}
	if (ac == 2)
	{
		std::cout << "Please enter more than one number" << std::endl;
		return 1;
	}
	SortDeez sort(av + 1);
	return 0;
}