/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:28:01 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/14 15:22:33 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T> 
int easyfind(T &container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw std::exception();
	return *std::find(container.begin(), container.end(), n);
}

#endif