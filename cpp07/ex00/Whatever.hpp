/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:25:59 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/13 12:46:24 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T> T min(T x, T y)
{
	return (x < y) ? x : y;
}
#endif