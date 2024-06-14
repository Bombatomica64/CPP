/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:41:45 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/14 13:08:37 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]), m_size(n) {}

template <typename T>
Array<T>::Array(Array const& src) : m_array(new T[src.m_size]), m_size(src.m_size) {
	for (unsigned int i = 0; i < m_size; i++)
		m_array[i] = src.m_array[i];
}

template <typename T>
Array<T>::~Array() {
	delete[] m_array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& src) {
	if (this != &src) {
		delete[] m_array;
		m_array = new T[src.m_size];
		m_size = src.m_size;
		for (unsigned int i = 0; i < m_size; i++)
			m_array[i] = src.m_array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= m_size)
		throw Array::OutOfBounds();
	return m_array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return m_size;
}


template <typename T>
const char* Array<T>::OutOfBounds::what() const throw() {
	return "Error: out of bounds";
}