/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:22:29 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/24 16:53:36 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::initMonthDays()
{
	monthDays.insert(std::pair<int, int>(1, 31));
	monthDays.insert(std::pair<int, int>(2, 28));
	monthDays.insert(std::pair<int, int>(3, 31));
	monthDays.insert(std::pair<int, int>(4, 30));
	monthDays.insert(std::pair<int, int>(5, 31));
	monthDays.insert(std::pair<int, int>(6, 30));
	monthDays.insert(std::pair<int, int>(7, 31));
	monthDays.insert(std::pair<int, int>(8, 31));
	monthDays.insert(std::pair<int, int>(9, 30));
	monthDays.insert(std::pair<int, int>(10, 31));
	monthDays.insert(std::pair<int, int>(11, 30));
	monthDays.insert(std::pair<int, int>(12, 31));
}

BitcoinExchange::BitcoinExchange()
: m_fileName(""), m_bitcoinValues()
{
	initMonthDays();
	getData();
	// std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string fileName) 
: m_fileName(fileName), m_bitcoinValues()
{
	initMonthDays();
	getData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	m_fileName = copy.m_fileName;
	m_bitcoinValues = copy.m_bitcoinValues;
	return *this;
}


void BitcoinExchange::getData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Invalid data file" << std::endl;
		return ;
	}
	
	std::string line;
	std::string date;
	std::string value;

	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Invalid data" << std::endl;
		return ;
	}

	while (std::getline(file, line))
	{
		// std::cout << RED << line << RESET << std::endl;
		date = line.substr(0, line.find(","));
		value = line.substr(line.find(",") + 1);
		if (!(IsDateValid(date)))
		{
			std::cerr << "Invalid data" << std::endl;
			return ;
		}
		m_bitcoinValues[date] = std::strtod(value.c_str(), NULL);
	}
}


void BitcoinExchange::readFromFile(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	std::string line;
	std::string date;
	std::string value;
	double btcValue;

	if (!file.is_open())
	{
		std::cerr << "Invalid input file" << std::endl;
		return ;
	}

	std::getline(file, line);

	if (line != "date | value" || line.empty())
	{
		std::cerr << "Invalid input file" << std::endl;
		return ;
	}
	while(std::getline(file, line))
	{
		date = line.substr(0, line.find("|"));
		value = line.substr(line.find("|") + 1);
		if (IsDateValid(date) == false || IsValueValid(value) == false)
			continue ;
		if (m_bitcoinValues.find(date) == m_bitcoinValues.end())
			date = getPrevDate(date);
		btcValue = static_cast<double>(m_bitcoinValues[date]) * std::strtod(value.c_str(), NULL);
		std::cout << date << " =>" << value << " = " << btcValue <<std::endl;
	}

}

bool BitcoinExchange::IsDateValid(std::string date)
{
	if (date.size() > 11 || date.size() < 10)
	{
		std::cerr << "Error: Invalid date format" << std::endl;
		return false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else if (date[i] < '0' || date[i] > '9')
			return false;
	}
	int year = std::atoll((date.substr(0, 4)).c_str());
	int month = std::atoll((date.substr(5, 2)).c_str());
	int day = std::atoll((date.substr(8, 2)).c_str());
	
	if (year < 2009 || year > 2024)
	{
		std::cerr << "Error: Invalid year" << std::endl;
		return false;
	}
		
	int flag = 0;

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		flag = 1;

	if (month < 1 || month > 12)
	{
		std::cerr << "Error: Invalid month" << std::endl;
		return false;
	}
	if (day < 1 || day > monthDays[month] + 1)
	{
		std::cout << month << std::endl << monthDays[month] << std::endl;
		std::cerr << "Error: Invalid day" << std::endl;
		return false;
	}
	
	return true;
}

bool BitcoinExchange::IsValueValid(std::string value)
{
	int dot = 0;
	if (value.size() == 0)
	{
		std::cerr << "Error: Empty value" << std::endl;
		return false;
	}
	unsigned int i = 0;
	for (; value[i] == ' '; i++)
	{
		// std::cout << "space" << std::endl;
	}
	if (value[i] == '-')
	{
		std::cerr << "Error: Negative value" << std::endl;
		return false;
	}
	for (unsigned int k = 0; k < value.size(); k++)
	{
		if (value[k] == '.')
			dot++;
		if ((value[k] < '0' || value[k] > '9') && value[k] != ' ')
		{
			if (value[k] != '.')
			{
				std::cerr << "Error: Non number value" << std::endl;
				return false;
			}
		}
	}
	if (dot > 1)
	{
		std::cerr << "Error: Invalid value" << std::endl;
		return false;
	}
	if (std::strtod(value.c_str(), NULL) < 0)
	{
		std::cerr << "Error: Negative value" << std::endl;
		return false;
	}
	if (std::strtod(value.c_str(), NULL) > 1000)
	{
		std::cerr << "Error: Too high value" << std::endl;
		return false;
	}
	return true;
}

std::string BitcoinExchange::getPrevDate(std::string date)
{
	int year = std::atoll((date.substr(0, 4)).c_str());
	int month = std::atoll((date.substr(5, 2)).c_str());
	int day = std::atoll((date.substr(8, 2)).c_str());
	std::string prevDate = date;
	while(true)
	{
		if (day > 1)
			day--;
		else
		{
			if (month > 1)
			{
				month--;
				day = monthDays[month];
			}
			else
			{
				year--;
				month = 12;
				day = monthDays[month];
			}
		}
		std::stringstream ss;
		ss << year << "-";
		if (month < 10)
			ss << "0";
		ss << month << "-" ;
		if (day < 10)
			ss << "0";
		ss << day;
		prevDate = ss.str();
		if (m_bitcoinValues.find(prevDate) != m_bitcoinValues.end())
			break;
		if (year < 2009)
		{
			prevDate = m_bitcoinValues.begin()->first;
			break;
		}
	}
	return prevDate;
}