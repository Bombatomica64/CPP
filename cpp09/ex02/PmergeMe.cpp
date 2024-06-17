/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:58:07 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/17 16:58:16 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

SortDeez::SortDeez(char **av)
{
	parse(av);
	sort();
	// print();
}

SortDeez::SortDeez( SortDeez const& copy )
{
	*this = copy;
}

SortDeez::~SortDeez( void )
{
}

SortDeez& SortDeez::operator=( SortDeez const& copy )
{
	if (this != &copy)
	{
		m_list = copy.m_list;
		m_vector = copy.m_vector;
	}
	return *this;
}

bool SortDeez::isInt( std::string str )
{
	std::istringstream iss(str);
	int f;
	if (!(iss >> f))
		return false;
	char c;
	if (iss >> c)
		return false;
	if (f < 0)
		return false;
	return true;
}

void SortDeez::parse( char **av )
{
	for (int i = 0; av[i]; i++)
	{
		if (isInt(av[i]))
		{
			m_list.push_back(std::atoi(av[i]));
			m_vector.push_back(std::atoi(av[i]));
		}
		else
		{
			std::cout << "Error: " << av[i] << " is not a valid number" << std::endl;
			exit(1);
		} 
	}
}

template <typename T>
void mergeVector(std::vector<T>& result, unsigned int startLeft, unsigned int middle, unsigned int endRight)
{
	std::vector<T> vecLeft(result.begin() + startLeft, result.begin() + middle + 1);
	std::vector<T> vecRight(result.begin() + middle + 1, result.begin() + endRight + 1);

	unsigned int iLeft = 0;
	unsigned int iRight = 0;
	unsigned int index = startLeft;
	while (iLeft < vecLeft.size() && iRight < vecRight.size())
	{
		if (vecLeft[iLeft] <= vecRight[iRight])
			result[index++] = vecLeft[iLeft++];
		else
			result[index++] = vecRight[iRight++];
	}

	while (iLeft < vecLeft.size())
		result[index++] = vecLeft[iLeft++];
	
	while (iRight < vecRight.size())
		result[index++] = vecRight[iRight++];
}

template <typename T>
void mergeSort(std::vector<T>& vec, unsigned int left, unsigned int right)
{
	if (left < right)
	{
		unsigned int middle = left + (right - left) / 2;
		mergeSort(vec, left, middle);
		mergeSort(vec, middle + 1, right);
		mergeVector(vec, left, middle, right);
	}
}

template <typename T>
void mergeList(std::list<T>& result, typename std::list<T>::iterator startLeft, typename std::list<T>::iterator middle, typename std::list<T>::iterator endRight)
{
	std::list<T> listLeft(startLeft, middle);
	std::list<T> listRight(middle, endRight);

	typename std::list<T>::iterator iLeft = listLeft.begin();
	typename std::list<T>::iterator iRight = listRight.begin();
	typename std::list<T>::iterator index = startLeft;
	while (iLeft != listLeft.end() && iRight != listRight.end())
	{
		if (*iLeft <= *iRight)
			*index++ = *iLeft++;
		else
			*index++ = *iRight++;
	}

	while (iLeft != listLeft.end())
		*index++ = *iLeft++;
	
	while (iRight != listRight.end())
		*index++ = *iRight++;
}

void SortDeez::sort( void )
{
	std::cout << " Numbers: ";
	for (size_t i = 0; i < m_vector.size(); i++)
	{
		std::cout << m_vector[i] << " ";
	}
	std::cout << std::endl;

	clock_t start = clock();
	time_t start_t = time(0);
	std::cout << start_t << std::endl;
	std::cout << start << std::endl;

	int OddOne;
	if (m_vector.size() % 2 == 0)
		OddOne = -1;
	else
	{
		OddOne = m_list.back();
		m_list.pop_back();
		m_vector.pop_back();
	}
	mergeSort(m_vector, 0, m_vector.size() - 1);
	std::list<int>::iterator it = m_list.begin();
	std::advance(it, m_vector.size() / 2);
	mergeList(m_list, m_list.begin(), it, m_list.end());
	if (OddOne != -1)
	{
		m_list.push_back(OddOne);
		m_vector.push_back(OddOne);
	}
}