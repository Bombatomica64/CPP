/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:26:02 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/15 18:26:44 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <string>
#include <sstream>

class BitcoinExchange
{
	private:
		std::string m_fileName;
		std::map<std::string, double> m_bitcoinValues;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void		readFromFile(std::string fileName);
		void		getData();
		bool		IsDateValid(std::string date);
		bool		IsValueValid(std::string value);
		std::string	getPrevDate(std::string date);
};

#endif