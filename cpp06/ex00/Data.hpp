/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:37:00 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/21 12:24:31 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <climits>

int		 	get_type(std::string const &str);
void		charLiteral(std::string const &str);
void		PseudoLiteral(std::string const &str);
void		floatLiteral(std::string const &str);
void		doubleLiteral(std::string const &str);
void		intLiteral(std::string const &str);

#endif