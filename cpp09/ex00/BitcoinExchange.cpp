/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:22:29 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/15 18:33:49 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
: m_fileName(""), m_bitcoinValues()
{
	getData();
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string fileName) 
: m_fileName(fileName), m_bitcoinValues()
{
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
		exit(1);
	}
	
	std::string line;
	std::string date;
	std::string value;

	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Invalid data" << std::endl;
		exit(1);
	}

	while (std::getline(file, line))
	{
		date = line.substr(0, line.find(","));
		value = line.substr(line.find(",") + 1);
		if (!(IsDateValid(date) || !IsValueValid(value)))
		{
			std::cerr << "Invalid data" << std::endl;
			exit(1);
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
		exit(1);
	}

	std::getline(file, line);

	if (line != "date | value" || line.empty())
	{
		std::cerr << "Invalid input file" << std::endl;
		exit(1);
	}
	
	while(std::getline(file, line))
	{
		date = line.substr(0, line.find("|"));
		value = line.substr(line.find("|") + 1);
		if (!IsValueValid(value) || !IsDateValid(date))
			continue;
		if (m_bitcoinValues.find(date) == m_bitcoinValues.end())
			date = getPrevDate(date);
		btcValue = m_bitcoinValues[date] * std::strtod(value.c_str(), NULL);
		std::cout << date << "=>" << value << "=" << btcValue <<std::endl;
	}

}

bool BitcoinExchange::IsDateValid(std::string date)
{
	if (date.size() != 10)
		return false;
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
		
	std::map<int, int> monthDays;
	monthDays[1] = 31;
	monthDays[2] = 28;
	monthDays[3] = 31;
	monthDays[4] = 30;
	monthDays[5] = 31;
	monthDays[6] = 30;
	monthDays[7] = 31;
	monthDays[8] = 31;
	monthDays[9] = 30;
	monthDays[10] = 31;
	monthDays[11] = 30;
	monthDays[12] = 31;

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		monthDays[2] = 29;

	if (month < 1 || month > 12)
	{
		std::cerr << "Error: Invalid month" << std::endl;
		return false;
	}

	if (day < 1 || day > monthDays[month])
	{
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
	if (value[0] == '-')
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
		if (m_bitcoinValues.find(date) != m_bitcoinValues.end())
			break;
		if (day > 1)
			day--;
		else
		{
			if (month > 1)
			{
				month--;
				day = 31;
			}
			else
			{
				year--;
				month = 12;
				day = 31;
			}
		}
		std::stringstream ss;
		ss << year << "-" << month << "-" << day;
		prevDate = ss.str();
		if (year < 2009)
		{
			prevDate = m_bitcoinValues.begin()->first;
			break;
		}
	}
	return prevDate;
}