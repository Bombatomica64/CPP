/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:36:27 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/17 16:18:19 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <sstream>

class SortDeez
{
	private:
		std::list<int> m_list;
		std::vector<int> m_vector;
		SortDeez() {}

	public:
		SortDeez(char **av);
		SortDeez(SortDeez const& copy);
		~SortDeez();

		SortDeez& operator=(SortDeez const& copy);

		void	parse(char **av);
		void	sort();
		// void	print();

		bool	isInt(std::string str);
};

#endif