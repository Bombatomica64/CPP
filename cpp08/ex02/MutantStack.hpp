/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:58:51 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/14 18:31:04 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const& copy);
		virtual ~MutantStack();
		MutantStack& operator=(MutantStack const& copy);
		iterator begin( void );
		iterator end( void );
	class iterator
	{
		public:
			iterator();
			iterator(iterator const& copy);
			iterator(MutantStack* stack);
			virtual ~iterator();
			iterator& operator=(iterator const& copy);
			iterator& operator++();
			iterator operator++(int);
			iterator& operator--();
			iterator operator--(int);
			int& operator*();
			bool operator==(iterator const& other);
			bool operator!=(iterator const& other);
		private:
			MutantStack* m_stack;
			int m_index;
	};
};

#endif