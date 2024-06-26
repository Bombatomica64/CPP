/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:58:11 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/17 15:28:24 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
class Calculator
{
	private:
	std::stack<int> 	m_numbers;
	std::stack<char>	m_operators;
	int 				m_result;
	Calculator();

	public:
		Calculator(std::string str);
		Calculator(Calculator const& copy);
		~Calculator();

		Calculator& operator=(Calculator const& copy);
		void		calculate();
		void		parse(std::string str);
};

#endif