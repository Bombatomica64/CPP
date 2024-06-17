/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:04:59 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/17 15:32:37 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Calculator::Calculator( void ) : m_result(0)
{
}

Calculator::Calculator( std::string str ) : m_result(0)
{
	parse(str);
	calculate();
}

Calculator::Calculator( Calculator const& copy )
{
	*this = copy;
}

Calculator::~Calculator( void )
{
}

Calculator& Calculator::operator=( Calculator const& copy )
{
	if (this != &copy)
	{
		m_numbers = copy.m_numbers;
		m_operators = copy.m_operators;
		m_result = copy.m_result;
	}
	return *this;
}

void Calculator::parse( std::string str )
{
	std::string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it == ' ')
			;
		else if (*it >= '0' && *it <= '9')
		{
			m_numbers.push(*it - '0');
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '%')
		{
			m_operators.push(*it);
		}
		else
		{
			std::cerr << "Invalid character: " << *it << std::endl;
			exit(1);
		}
		it++;
	}
	if (m_numbers.size() != m_operators.size() + 1)
	{
		std::cerr << "Invalid expression" << std::endl;
		exit(1);
	}
}

void Calculator::calculate( void )
{
	try {
	while (!m_operators.empty())
	{
		int a = m_numbers.top();
		m_numbers.pop();
		int b = m_numbers.top();
		m_numbers.pop();
		char op = m_operators.top();
		m_operators.pop();
		switch (op)
		{
			case '+':
				m_numbers.push(b + a);
				break;
			case '-':
				m_numbers.push(b - a);
				break;
			case '*':
				m_numbers.push(b * a);
				break;
			case '/':
				if (a == 0)
					throw std::runtime_error("Division by zero");
				m_numbers.push(b / a);
				break;
			case '%':
				m_numbers.push(b % a);
				break;
		}
	}
	m_result = m_numbers.top();
	std::cout << m_result << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}