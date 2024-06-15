/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:22:29 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/15 16:56:39 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
: m_fileName(""), m_data(NULL), m_bitcoinValues()
{
}

BitcoinExchange::BitcoinExchange(std::string fileName) 
: m_fileName(fileName), m_data(NULL), m_bitcoinValues()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
	if (m_data)
		delete[] m_data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	m_fileName = copy.m_fileName;
	if (m_data)
		delete[] m_data;
	m_data = new std::string*[copy.m_bitcoinValues.size()];
	m_data = copy.m_data;
	m_bitcoinValues = copy.m_bitcoinValues;
	return *this;
}

void BitcoinExchange::readFromFile(std::string fileName)
{
	std::ifstream file(fileName);
	std::string line;
	std::string date;
	std::string value;
	int i = 0;

	if (!file.is_open())
	{
		std::cerr << "Invalid file" << std::endl;
		exit(1);
	}

	std::getline(file, line, '\0');
}