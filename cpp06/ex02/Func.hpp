/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Func.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:54:16 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/13 12:16:40 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_HPP
#define FUNC_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <tr1/random>

void init_rand( void );

class InitRandCaller {
public:
	InitRandCaller() {
		init_rand();
	}
};

Base *generate( void );
void identify( Base *p );
void identify( Base &p );

#endif