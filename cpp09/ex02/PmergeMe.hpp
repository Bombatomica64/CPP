/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:36:27 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/17 18:18:39 by lmicheli         ###   ########.fr       */
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

	public:
		SortDeez(char **av);
		SortDeez(SortDeez const& copy);
		~SortDeez();

		SortDeez& operator=(SortDeez const& copy);

		void	parse(char **av);
		void	sort();

		bool	isInt(std::string str);
};

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define BOLDWHITE "\033[1;37m"
# define RESET "\033[0m"

#endif