/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:38:11 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/07 12:05:51 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Data.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter &operator=(ScalarConverter const &rhs);

	public:
		~ScalarConverter();
		void	convert(std::string const &str);
};

#endif